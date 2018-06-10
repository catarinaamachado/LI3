package common;

/**
 * Classe que compara a reputação dos utilizadores.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180610
 */

import java.util.Comparator;

public class UsersComparator implements Comparator<Users> {
  /**
   * Método que ordena os utilizadores por ordem decrescente da reputação.
   * Caso dois utilizadores terem a mesma reputação ordena os utlizadores
   * por ordem decrescente do id dos mesmo.
   * 
   * @param u1 um utilizador;
   * @param u2 um utilizador;
   * 
   * @returns int - Comparador de dois utilizadores.
   */
    public int compare(Users u1, Users u2) {
        int result = (u2.getReputation() - u1.getReputation());
        
        
        return (result != 0)? result : ((int)u2.getUsersId() - (int)u1.getUsersId());
    }
}
