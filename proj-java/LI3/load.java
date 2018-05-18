
/**
 * Escreva a descrição da classe load aqui.
 * 
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180519
 */

import javax.xml.parsers.*;
import org.xml.sax.*;
import org.xml.sax.helpers.*;

import java.util.*;
import java.io.*;

public class Load {
    
    public Load() {
    }
    
    public void lerFicheiros(TCD_Community com) throws Exception{
        String filenamePosts = "../../dump/android/Posts.xml";        
        String filenameUsers = "../../dump/android/Users.xml";
        String filenameTags = "../../dump/android/Tags.xml";
        
        SAXParserFactory spf = SAXParserFactory.newInstance();
        spf.setNamespaceAware(true);
        SAXParser saxParser = spf.newSAXParser(); //cria um parser
        XMLReader xmlReader = saxParser.getXMLReader(); //cria um xmlreader
        xmlReader.setContentHandler(new SAXParsePosts());
        xmlReader.parse(filename);

    }
}
