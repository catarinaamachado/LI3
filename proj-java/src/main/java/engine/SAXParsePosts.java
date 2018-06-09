package engine;

/**
 * Parse ao dump de Posts.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180519
 */

import common.*;
import org.xml.sax.helpers.*;
import org.xml.sax.*;

import java.time.LocalDate;

public class SAXParsePosts extends DefaultHandler {

    private TCD_Community com;
    
    /**
     * Construtor parametrizado.
     * @param com - Estrutura de dados TCD_Community.
     */
    public SAXParsePosts(TCD_Community com) {
        super();
        this.com = com;
    }

    /**
     * Função que extrai os elementos necessários dos posts para preencher as
     * respetivas estruturas de dados.
     * @param namespaceURI - String usada para identificar um recurso na Internet.
     * @param localName - Nome do elemento.
     * @param qName - Combinação do namespace com o nome do elemento.
     * @param atts -  Lista de atributos de um elemento.
     * 
     * @throws SAXException
     * 
     */
    public void startElement(String namespaceURI,
                             String localName,
                             String qName,
                             Attributes atts) throws SAXException{

        int length = atts.getLength(); //retorna o tamanho da lista de atributos

        int id, post_type_id, owner_id, title, tags, score, comment_count, parentid, date;

        boolean was_null = false;

        post_type_id = parentid = owner_id = title = tags = date = 0;
        id = score = comment_count = -1;

        for (int i=0; i < length; i++) {
            String name = atts.getQName(i); //retorna o nome do elemento

            if(name.equals("Id"))
                id = i;

            else if (name.equals("PostTypeId"))
                post_type_id = i;

            else if (name.equals("OwnerUserId"))
                owner_id = i;

            else if (name.equals("Title"))
                title = i;

            else if (name.equals("Tags"))
                tags = i;

            else if (name.equals("Score"))
                score = i;

            else if (name.equals("CommentCount"))
                comment_count= i;

            else if (name.equals("ParentId"))
                parentid = i;

            else if (name.equals("CreationDate"))
                date = i;
        }

        if (length != 0) {

            
            //se o post não for nem uma pergunta, nem uma resposta
            if (!atts.getValue(post_type_id).equals("1") && !atts.getValue(post_type_id).equals("2"))
                return;


            if (atts.getValue(post_type_id).equals("1")) { //o post é uma pergunta
                long questionId = Long.parseLong(atts.getValue(id));

                Question pergunta = com.lookQuestion(questionId);

                if (pergunta == null) {
                    was_null = true;
                    pergunta = new Question();

                    pergunta.setPostId(questionId);
                    pergunta.setNAnswers(0);
                    pergunta.setNAnswerVotes(0);

                }

                pergunta.setUserId(Long.parseLong(atts.getValue(owner_id)));

                pergunta.setTitle(atts.getValue(title));

                pergunta.setTags(atts.getValue(tags));

                if(date != 0) {
                    String[] ymd = atts.getValue(date).split("-");
                    String[] d = ymd[2].split("T");
                    LocalDate pd = LocalDate.of(
                            Integer.parseInt(ymd[0]),
                            Integer.parseInt(ymd[1]),
                            Integer.parseInt(d[0])
                    );
                    pergunta.setPd(pd);
                }
                else
                    pergunta.setPd(LocalDate.MIN);

                if(was_null)
                    com.insertQuestion(pergunta);

                if(owner_id != 0) {
                    long ownerId = Long.parseLong(atts.getValue(owner_id));
                    Users u = com.lookUser(ownerId);

                    if(u != null) {
                        u.incrementaNPosts();
                        u.addPost(pergunta);
                    }
                }
            }

            else if(parentid != 0) {  // se for uma resposta
                Answer resposta = new Answer();

                resposta.setPostId(Long.parseLong(atts.getValue(id)));
                resposta.setUserId(Long.parseLong(atts.getValue(owner_id)));
                resposta.setParentId(Long.parseLong(atts.getValue(parentid)));

                if(date != 0) {
                    String[] ymd = atts.getValue(date).split("-");
                    String[] d = ymd[2].split("T");
                    LocalDate pd = LocalDate.of(
                            Integer.parseInt(ymd[0]),
                            Integer.parseInt(ymd[1]),
                            Integer.parseInt(d[0])
                    );
                    resposta.setPd(pd);
                }
                else
                    resposta.setPd(LocalDate.MIN);

                resposta.setScore(Integer.parseInt(atts.getValue(score)));
                resposta.setCommentCount(Integer.parseInt(atts.getValue(comment_count)));

                com.insertAnswers(resposta);

                if(owner_id != 0) {
                    long ownerId = Long.parseLong(atts.getValue(owner_id));
                    Users u = com.lookUser(ownerId);

                    if(u != null) {
                        u.incrementaNPosts();
                        u.addPost(resposta);
                    }
                }

                long parentId = resposta.getParentId();

                Question pergunta = com.lookQuestion(parentId);

                if(pergunta != null) {
                    pergunta.setNAnswerVotes(pergunta.getNAnswerVotes() + resposta.getScore());
                    pergunta.setNAnswers(pergunta.getNAnswers() + 1);
                    pergunta.addAnswertoAnswersList(resposta);
                }
                else { // a pergunta não existe
                    pergunta = new Question();

                    pergunta.setUserId(0);
                    pergunta.setTitle("");
                    pergunta.setTags("");

                    pergunta.setPd(LocalDate.MIN);

                    pergunta.setNAnswers(1); //poe o numero de respostas a 1
                    pergunta.setPostId(parentId); //poe o id da pergunta com o parent id da resposta

                    pergunta.setNAnswerVotes(resposta.getScore()); //estabelece o numero de votos
                    pergunta.addAnswertoAnswersList(resposta);

                    com.insertQuestion(pergunta);
                }

                //addDAYAnswers(pointerDay, pointer); //adiciona uma resposta ao GPtrArray answers da struct day
            }
        }
    }
}
