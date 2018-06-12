package common;

/**
 * Classe que compara a reputação dos users.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180610
 */

import java.util.Comparator;

public class PostComparator implements Comparator<Posts> {
  /**
   * Método que ordena os posts por ordem decrescente da data dos mesmos.
   * Caso dois posts terem a mesma data, ordena os posts
   * por ordem decrescente do id dos mesmos.
   * 
   * @param a um post;
   * @param b um post;
   * 
   * @returns int - Comparador de dois posts.
   */    
    public int compare(Posts a, Posts b) {
        if(a.getPd().isAfter(b.getPd()))
            return -1;
        if(a.getPd().isBefore(b.getPd()))
            return 1;

        if (a.getPostId() < b.getPostId())
            return 1;
        if (a.getPostId() > b.getPostId())
            return -1;

        return 0;
    }
}
