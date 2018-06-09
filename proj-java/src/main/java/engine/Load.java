package engine;

/**
 * Classe que carrega dados do dump xml.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180519
 */

import java.io.IOException;
import javax.xml.parsers.*;
import org.xml.sax.*;

public class Load {

	public Load() {
	}

	public void lerFicheiros(TCD_Community com, String dumpPath) throws
			SAXException,
			ParserConfigurationException,
	        IOException {

		String filenamePosts = dumpPath + "/Posts.xml";
		String filenameUsers = dumpPath + "/Users.xml";
		String filenameTags = dumpPath + "/Tags.xml";

		SAXParserFactory spf = SAXParserFactory.newInstance(); //cria uma instância do objeto
		spf.setNamespaceAware(true);
		SAXParser saxParser = spf.newSAXParser(); //cria um parser
		XMLReader xmlReader = saxParser.getXMLReader(); //cria um xmlreader


		xmlReader.setContentHandler(new SAXParseUsers(com)); //ContentHandler define quais os callbacks
		xmlReader.parse(filenameUsers);

		xmlReader.setContentHandler(new SAXParsePosts(com));
		xmlReader.parse(filenamePosts);

		xmlReader.setContentHandler(new SAXParseTags(com));
		xmlReader.parse(filenameTags);
	}
}
