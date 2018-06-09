package common;

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
