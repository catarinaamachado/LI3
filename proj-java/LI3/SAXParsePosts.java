
/**
 * Escreva a descrição da classe SAXParsePosts aqui.
 * 
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180519
 */

import org.xml.sax.helpers.*;
import org.xml.sax.*;

public class SAXParsePosts extends DefaultHandler {
    
    private TCD_Community com;
    
    public SAXParsePosts(TCD_Community com) {
        super();
        this.com = com;
    }
    
    public void startElement(String namespaceURI,
                             String localName,
                             String qName, 
                             Attributes atts) throws SAXException {
        
    int length = atts.getLength();
     
    int id, post_type_id, owner_id, title, tags, score, comment_count, favorite_count, was_null;
    int parentid, date;

    post_type_id = parentid = owner_id = title = tags = date = was_null = 0;
    id = score = favorite_count = comment_count = -1;

        for (int i=0; i < length; i++) {
            String name = atts.getQName(i);
            
            if(name.equals("Id"))
                id = i; //will increment the value of i, and then return the incremented value

            else if(name.equals("PostTypeId")) 
                post_type_id = i;

            else if(name.equals("OwnerUserId"))
                owner_id = i;

            else if(name.equals("Title"))
                title = i;

            else if(name.equals("Tags"))
                tags = i;

            else if(name.equals("Score"))
                score = i;

            else if(name.equals("CommentCount"))
                comment_count= i;

            else if(name.equals("ParentId"))
                parentid = i;

            else if(name.equals("CreationDate"))
                date = i;
        }
        
        if(length != 0) {
        
            if(!atts.getValue(post_type_id).equals("1") && 
               !atts.getValue(post_type_id).equals("2"))
            
               return;
              
        }
     
     

    
    }
}
