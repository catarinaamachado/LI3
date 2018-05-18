
/**
 * Escreva a descrição da classe load aqui.
 * 
 * @author (seu nome) 
 * @version (número de versão ou data)
 */

import javax.xml.parsers.*;
import org.xml.sax.*;
import org.xml.sax.helpers.*;

import java.util.*;
import java.io.*;


public class load
{
    
    static public void main(String[] args) throws Exception {
        String filename = "/Users/cecilia/Documents/Universidade/2ANO/LI3/dumpExemplo/android/Posts.xml";
        
        SAXParserFactory spf = SAXParserFactory.newInstance();
        spf.setNamespaceAware(true);
        SAXParser saxParser = spf.newSAXParser(); //cria um parser
        XMLReader xmlReader = saxParser.getXMLReader(); //cria um xmlreader
        xmlReader.setContentHandler(new SAXParsePosts());
        xmlReader.parse(filename);

    }
}
