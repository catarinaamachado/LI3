package common;

/**
 * Classe que compara o número de posts de um utilizador.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180519
 */

import java.util.Comparator;

public class NumeroPostsComparador implements Comparator<Users> {
   
  /**
   * Método que ordena os usuários por ordem decrescente do número de posts.
   * Caso dois usuários tenham o mesmo número de posts ordena os usuários
   * por ordem crescente do número de identificador dos mesmos.
   * 
   * @param u1 um user;
   * @param u2 um user;
   * 
   * @returns int - Comparador dos dois usuários.
   */
    public int compare(Users u1, Users u2) {
    int result = (u2.getNPosts() - u1.getNPosts());
    
    return (result != 0)? result : ((int)u1.getUsersId() - (int)u2.getUsersId());
  }
    
}
