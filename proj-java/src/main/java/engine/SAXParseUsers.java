package engine;

/**
 * Parse dump de Users.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180519
 */

import org.xml.sax.helpers.*;
import org.xml.sax.*;
import common.*;

public class SAXParseUsers extends DefaultHandler {

    private TCD_Community com;

    /**
     * Contrutor parametrizado.
     * 
     * @param com - Estrutura de dados TDC_Community.
     */
    public SAXParseUsers(TCD_Community com) {
        super();
        this.com = com;
    }

    /**
     * Função que extrai os elementos necessários dos usuários para preencher as
     * respetivas estruturas de dados.
     * @param namespaceURI - String usada para identificar um recurso na Internet.
     * @param localName - Nome do elemento.
     * @param qName - Combinação do namespace com o nome do elemento.
     * @param atts -  Lista de atributos de um elemento.
     * 
     * @throws SAXException
     */
    public void startElement(String namespaceURI,
                             String localName,
                             String qName,
                             Attributes atts) throws SAXException {

       int length = atts.getLength();
       int id, reputation, name, about;
       id = reputation = name = about = 0;
       long userId;

       for (int i = 0; i < length; i++) {
            String atributo = atts.getQName(i); //como ir buscar o conteudo dos atributos (atts)

            if(atributo.equals("Id"))
                id = i;

            else if(atributo.equals("Reputation"))
                reputation = i;

            else if(atributo.equals("DisplayName"))
                name = i;

            else if(atributo.equals("AboutMe"))
                about = i;
       }

       if(length != 0) {

           userId = Long.parseLong(atts.getValue(id));
           Users user = new Users();

           user.setUserName(atts.getValue(name));

           if(about != 0) {
               user.setUserBio(atts.getValue(about));
            }
           else {
               user.setUserBio("");
            }

           user.setReputation(Integer.parseInt(atts.getValue(reputation)));
           user.setNPosts(0);
           user.setUserId(userId);

           com.insertUser(user);
        }
    }
}