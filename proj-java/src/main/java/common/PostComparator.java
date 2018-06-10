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
