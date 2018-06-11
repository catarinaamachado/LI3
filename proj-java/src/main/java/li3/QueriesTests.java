package li3;

import engine.TCD_Community;
import common.*;


import org.xml.sax.SAXException;
import java.io.IOException;
import javax.xml.parsers.ParserConfigurationException;

import static org.junit.Assert.*;
import org.junit.After;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import org.junit.rules.ExpectedException;
import java.util.*;

/**
 * Classe de testes das queries.
 *
 * * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180611
 */
public class QueriesTests {
    private static TCD_Community com;
    
    
    /**
     * Método que carrega a estrutura TCD_Community uma única vez antes de todos os testes.
     */
    @BeforeClass
    static public void setUpClass() throws SAXException, ParserConfigurationException, IOException {
        if (com == null) {
          com = new TCD_Community();
         

          com.load("../../../../dump/ubuntu");
        }
    }
    
    /**
     * Default constructor for test class QueriesTests
     */
    public QueriesTests()
    {
    }
    
    /**
     * Sets up the test fixture.
     *
     * Called before every test case method.
     */
    @Before
    public void setUp()
    {
    
    }

    /**
     * Tears down the test fixture.
     *
     * Called after every test case method.
     */
    @After
    public void tearDown()
    {
    }
    
    /**
     * Método que testa a query 1.
     */
    public void infoFromPostTest() throws NoPostIdException {
        Pair<String,String> q1 = new Pair("null", "null");
        Pair<String,String> q2 = new Pair("null", "null");
        Pair<String,String> q3 = new Pair("null", "null");
        Pair<String,String> q1Expected = new Pair("Is there a system-wide equalizer for PulseAudio or ALSA?", "jfoucher");
        Pair<String,String> q2Expected = new Pair("uninstall init.d update-rc.d remove", "ton.yeung");
        Pair<String,String> q3Expected = new Pair("Is there a real name policy in the Ubuntu community?", "martin001");
        
        q1 = com.infoFromPost(94);
        q2 = com.infoFromPost(327524);
        q3 = com.infoFromPost(113193);
        
        assertEquals("Par", q1Expected, q1);
        assertEquals("Par", q2Expected, q2);
        assertEquals("Par", q3Expected, q3);
        
    }
    
    /**
     * Método que testa a exceção da query 1, ou seja, quando o id passado como parametro não identifica um post.
     */
    @Test(expected = NoPostIdException.class)
    public void testNoPostIdException() throws NoPostIdException{
       Pair<String,String> q1 = new Pair("null", "null");
       Pair<String,String> q1Expected = new Pair("null", "null");
       
       q1 = com.infoFromPost(-94);

    }
    
    /**
     * Método que testa a query 2.
     */
    @Test
    public void topMostActiveTest() {
        List<Long> maisPublicamExpected = Arrays.asList(15811L, 449L, 158442L, 167850L, 367165L, 295286L, 59676L, 
                                                        93977L, 35795L, 3940L, 7035L, 19421L,14356L,1992L, 33833L, 
                                                        147044L, 169736L, 202806L, 235L, 150504L, 22949L, 94914L, 
                                                        178692L, 344926L,8500L, 216503L, 50737L, 225694L, 72216L, 
                                                        367990L, 58612L, 25618L, 19779L, 2369L, 4272L, 61218L, 
                                                        85695L, 167115L, 32239L, 6969L, 26246L, 10616L, 175814L, 
                                                        364819L, 25863L, 29012L, 260935L, 380067L, 88802L, 178596L); 
                                   
                                                     
        
        List<Long> maisPublicam = new ArrayList<>();
        
        maisPublicam = com.topMostActive(50);
        
        assertEquals("Lista de users mais ativos", maisPublicamExpected, maisPublicam);
    }
    
    
    /**
     * Método que testa a query 10.
     */
    @Test
    public void BetterAnswerTest() throws NoAnswersException, NoQuestionIdException {
        
       
        Long answer1 = com.betterAnswer(1);
        Long answer2 = com.betterAnswer(3);
        Long answer3 = com.betterAnswer(5942);
        
        assertEquals("Melhor resposta", Long.valueOf(2L), answer1);
        assertEquals("Melhor resposta", Long.valueOf(78806L), answer2);
        assertEquals("Melhor resposta", Long.valueOf(5963L), answer3);
        
        
    }
    
    /**
     * Método que testa a exceção NoAnswersException da query 10, ou seja, quando a pergunta
     * para a qual se pretende avaliar a melhor resposta não tem respostas.
     */
    @Test(expected = NoAnswersException.class)
    public void testNoAnswersException() throws NoAnswersException, NoQuestionIdException {
       Long result;
       
       result = com.betterAnswer(386);

    }
    
    /**
     * Método que testa a exceção NoQuestionIdException da query 10, ou seja, quando o Id
     * passado como parametro não identifica uma pergunta
     */
    @Test(expected = NoQuestionIdException.class)
    public void testNoQuestionIdException() throws NoAnswersException, NoQuestionIdException {
       Long result;
       
       result = com.betterAnswer(2);

    }
}
