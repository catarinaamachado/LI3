package engine;

/**
 * Classe que responde à query 1.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180531
 */

import common.*;

public class Query1 {
    
    private TCD_Community com;
   
    /**
     * Construtor parametrizado.
     *
     * @param com Estrutura de dados do TCD_Community
     */
    public Query1(TCD_Community com) {
        this.com = com;
    }
    
    
    /**
     * Dado o identificador de um post, o método retorna
     * o título do post e o nome (não o ID) de utilizador do autor. Caso o post não
     * possua título ou nome de utilizador, o resultado correspondente deverá
     * ser NULL.
     * Se o post for uma resposta, a função retorna informações (título e utilizador)
     * da pergunta correspondente.
     *
     * @param id - id do post
     * 
     * @returns Pair<String, String> - título e o nome do autor do pergunta
     * 
     * @throws NoPostIdException
     */
    public Pair<String,String> run(long id) throws NoPostIdException{
        long userId;
        long parentId;
        String title, username;
        
        Question pergunta = com.lookQuestion(id);
        
        if (pergunta == null) {
            Answer resposta = com.lookAnswer(id);
            
            if(resposta == null) {
                throw new NoPostIdException(id + " não identifica uma pergunta nem uma resposta");
            }
            
            if (resposta != null) {
                parentId = resposta.getParentId();
                pergunta = com.lookQuestion(parentId);
            }
        }
        
        if (pergunta != null) {
            userId = pergunta.getUserId();
            
            Users user = com.lookUser(userId);
            
            if (user == null) {
                return new Pair("null","null");
            }
            
            title = pergunta.getTitle();
            username = user.getUserName();
            
            if (title != null && username != null) {
                return new Pair<>(title, username);
            }
            
        }
        
        return new Pair("null","null");
    }
}
