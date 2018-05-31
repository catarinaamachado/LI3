
/**
 * Parse ao dump de Posts.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180519
 */

import org.xml.sax.helpers.*;
import org.xml.sax.*;

public class SAXParsePosts extends DefaultHandler {

    private TCD_Community com;

    public SAXParsePosts(TCD_Community com) {
        super();
        this.com = com;
    }

    public void startElement(String namespaceURI,
                             String localName,
                             String qName,
                             Attributes atts) throws SAXException {

    int length = atts.getLength();

    int id, post_type_id, owner_id, title, tags, score, comment_count, favorite_count;
    int parentid, date;

    boolean was_null = false;

    post_type_id = parentid = owner_id = title = tags = date = 0;
    id = score = favorite_count = comment_count = -1;

        for (int i=0; i < length; i++) {
            String name = atts.getQName(i); //como ir buscar o conteudo dos atributos

            if(name.equals("Id"))
                id = i;

            else if(name.equals("PostTypeId"))
                post_type_id = i;

            else if(name.equals("OwnerUserId"))
                owner_id = i;

            else if(name.equals("Title"))
                title = i;

            else if(name.equals("Tags"))
                tags = i;

            else if(name.equals("Score"))
                score = i;

            else if(name.equals("CommentCount"))
                comment_count= i;

            else if(name.equals("ParentId"))
                parentid = i;

            else if(name.equals("CreationDate"))
                date = i;
        }

        if(length != 0) {

            if(!atts.getValue(post_type_id).equals("1") &&
               !atts.getValue(post_type_id).equals("2"))

               return;



            /* FALTA TRATAR DATA
             * //carrega a estrutura postAndDate
        postDate pd = malloc(getPDSize()); // cria espaço na memoria para um postDate

        setPostId(pd, atol((char *)attributes[id])); //coloca o id do post

        setDate(pd, (char *)attributes[date]); //coloca a data do post em string (postDate.c) em pd


        GDate * d = g_date_new_dmy(getPDDay(pd), getPDMonth(pd), getPDYear(pd)); //a newly-allocated GDate initialized with day , month , and year of the post
        long indexDay = g_date_days_between(begin_stackOverflow, d); //Computes the number of days between two dates - begin_stackOverflow(15-09-2008)e post's date
        g_date_free(d); //liberta o apontador para GDate
        Day pointerDay = lookDay(structure, indexDay); //apontador para o dia contido num determinado índice do GPtrArray day.

             */

            if(atts.getValue(post_type_id).equals("1")) { //trata-se de uma pergunta
                long questionId = Long.parseLong(atts.getValue(id)); //converte o id do post num numero

                System.out.println("QuestionId :" + questionId);

                Question pergunta = com.lookQuestion(questionId); //procura uma pergunta na tabela de hash designada questions.

                if(pergunta == null) {
                    was_null = true;
                    pergunta = new Question();

                    pergunta.setPostId(questionId);
                    pergunta.setNAnswers(0);
                    pergunta.setNAnswerVotes(0);

                }

                pergunta.setUserId(Long.parseLong(atts.getValue(owner_id)));

                pergunta.setTitle(atts.getValue(title));

                pergunta.setTags(atts.getValue(tags));

                //setQDate(pointer, (char *)attributes[date]); //estabelece a data da pergunta na struct questions

                if(was_null)
                    com.insertQuestion(pergunta);

                //addDAYQuestions(pointerDay, pointer);//adiciona a pergunta ao array questions que está na estrutura day
            }

            else if(parentid != 0) {  // se for uma resposta
                Answers resposta = new Answers();

                resposta.setPostId(Long.parseLong(atts.getValue(id)));
                resposta.setUserId(Long.parseLong(atts.getValue(owner_id)));
                resposta.setParentId(Long.parseLong(atts.getValue(parentid)));


                resposta.setScore(Integer.parseInt(atts.getValue(score)));
                resposta.setCommentCount(Integer.parseInt(atts.getValue(comment_count)));

                com.insertAnswers(resposta);

                long parentId = resposta.getParentId();

                Question pergunta = com.lookQuestion(parentId);

                if(pergunta != null) {
                    pergunta.setNAnswers(pergunta.getNAnswerVotes() + resposta.getScore());
                    pergunta.setNAnswers(pergunta.getNAnswers() + 1);
                    pergunta.addAnswertoAnswersList(resposta);
                }
                else { // a pergunta não existe
                    pergunta = new Question();

                    pergunta.setUserId(0);
                    pergunta.setTitle("");
                    pergunta.setTags("");

                    //setQDate(q, 0); //estabelece a data da pergunta a NULL

                    pergunta.setNAnswers(1); //poe o numero de respostas a 1
                    pergunta.setPostId(parentId); //poe o id da pergunta com o parent id da resposta

                    pergunta.setNAnswerVotes(resposta.getScore()); //estabelece o numero de votos
                    pergunta.addAnswertoAnswersList(resposta);

                    com.insertQuestion(pergunta);
                }

                //addDAYAnswers(pointerDay, pointer); //adiciona uma resposta ao GPtrArray answers da struct day

            }

            if(owner_id != 0) {  //se o owner id existe, acrescenta posts aos utilizadores
                long ownerId = Long.parseLong(atts.getValue(owner_id));
                Users u = com.lookUser(ownerId);

                if(u != null) {
                    u.incrementaNPosts(); //acrescenta o numero de posts do user

                    //appendPost(u, pd); //Acrescenta ao array last_posts da estrutura users informação sobre a data do post.
                } else {
                    //cleanPD(pd);
                }
            } else {
                //cleanPD(pd);
            }
        }
    }
}
