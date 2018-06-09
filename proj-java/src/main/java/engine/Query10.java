package engine;

/**
 * Classe que responde à query 10.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180531
 */

import common.*;

public class Query10 {
   private TCD_Community com;
   
    /**
     * Construtor parametrizado.
     *
     * @param com Estrutura de dados do TCD_Community
     */
    public Query10(TCD_Community com) {
        this.com = com;
    }
    

    /**
     * Dado o ID de uma pergunta, obtem a melhor resposta.
     * Para isso, usa a função de média ponderada abaixo:
     * (score da resposta × 0.45) + (reputação do utilizador × 0.25) +
     * (número de votos recebidos pela resposta × 0.2) +
     * (número de comentários recebidos pela resposta × 0.1)   
     *
     * @param id - id da pergunta
     * 
     * @returns long - id da resposta
     * 
     * @throws NoAnswersException, NoQuestionIdException
     */
    public long run(long id) throws NoAnswersException, NoQuestionIdException {
        int i, total_answers, reputation, score, commentCount;
        long answerId = -1;
        double total, max = 0.0;
        
        Question pergunta = com.lookQuestion(id);
        
        if(pergunta == null) {
            throw new NoQuestionIdException("O id " + id + " não pertence a uma pergunta");
        }
        
        
        total_answers = pergunta.getNAnswers();
        
        if(total_answers == 0) {
            throw new NoAnswersException("A pergunta não tem nenhuma resposta");
        }
        
        
        for(i = 0; i < total_answers; i++) {
             Answers resposta = pergunta.getAnswersList().get(i);
             Users user = com.lookUser(resposta.getUserId());
             
             if(user == null) {
                 reputation = 0;
             }
             else {
                 reputation = user.getReputation();
             }
            
             score = resposta.getScore();
             commentCount = resposta.getCommentCount();
             
             total = score * 0.65 + reputation * 0.25 + commentCount * 0.1;
             
             if(total > max) {
                 max = total;
                 answerId = resposta.getPostId();
             }
        }
        
        return answerId;
    }
}
