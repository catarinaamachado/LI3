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

public class NumeroVotosRespostas implements Comparator<Answer> {
   
  /**
   * Método que ordena as respostas por ordem decrescente do número de votos.
   * Caso duas respostas tenham o mesmo número de votos ordena as respostas
   * por ordem decrescente do número de identificador das mesmas.
   * 
   * @param a1 uma resposta;
   * @param a2 uma resposta;
   * 
   * @returns int - Comparador das duas respostas.
   */
    public int compare(Answer a1, Answer a2) {
    int result = (a2.getScore() - a1.getScore());
    
    return (result != 0)? result : ((int)a2.getPostId() - (int)a1.getPostId());
  }
    
}
