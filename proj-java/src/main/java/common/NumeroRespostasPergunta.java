package common;

/**
 * Classe que compara o número de votos das respostas.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180609
 */

import java.util.Comparator;

public class NumeroRespostasPergunta implements Comparator<Question> {
   
  /**
   * Método que ordena as perguntas por ordem decrescente do número de respostas.
   * 
   * @param q1 uma pergunta;
   * @param q2 uma pergunta;
   * 
   * @returns int - Comparador das duas perguntas.
   */
    public int compare(Question q1, Question q2) {
    int result = (q2.getNAnswers() - q1.getNAnswers());
    
    return result;
  }
    
}
