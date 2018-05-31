package engine;
import common.*;


/**
 * Classe que responde à query10.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180531
 */
public class Query10
{
   TCD_Community com;
   
    /**
     * Construtor parametrizado.
     *
     * @param com Estrutura de dados do TCD_Community
     */
    Query10(TCD_Community com) {
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
     */
    public long run(long id) {
        int i, total_answers, reputation, score, commentCount;
        long answerId = -1;
        double total, max = 0.0;
        
        Question pergunta = com.lookQuestion(id);
        
        if(pergunta == null) {
            return answerId;
        }
        
        total_answers = pergunta.getNAnswers();
        //System.out.println("Numero de respostas " + total_answers);
        //System.out.println(pergunta.toString());
        
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
