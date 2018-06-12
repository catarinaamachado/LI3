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
import java.time.LocalDate;

/**
 * Classe de testes das queries.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180611
 */
public class TestQueries {
    private static TCD_Community com;


    /**
     * Método que carrega a estrutura TCD_Community uma única vez antes de todos os testes.
     */
    @BeforeClass
    static public void setUpClass() throws SAXException, ParserConfigurationException, IOException {
        if (com == null) {
          com = new TCD_Community();
          com.load(System.getProperty("path"));
        }
    }

    /**
     * Default constructor for test class QueriesTests
     */
    public TestQueries()
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
     * Método que testa a query 3.
     */
    @Test
    public void totalPostsTest() {
        LocalDate begin = LocalDate.of(2016, 7, 1);
        LocalDate end = LocalDate.of(2016, 7, 31);
        Pair<Long,Long> qtasPergResp = com.totalPosts(begin, end);
        Pair<Long,Long> qtasPergRespExpected = new Pair (3667L, 4102L);

       assertEquals("Quantas perguntas e respostas", qtasPergRespExpected, qtasPergResp);

    }

    /**
     * Método que testa a query 4.
     */
    @Test
    public void questionsWithTagTest() {
        LocalDate begin = LocalDate.of(2013, 3, 1);
        LocalDate end = LocalDate.of(2013, 3, 31);
        String tag = "package-management";

        List<Long> questionsWithTagExpected = Arrays.asList(276029L, 276174L, 274316L, 274324L, 274462L,
                                               272937L, 274100L, 274141L, 272565L, 272666L,
                                               272754L, 272813L, 272313L, 272450L, 271816L,
                                               271647L, 271683L, 270853L, 270188L, 270488L,
                                               270528L, 270608L, 269781L, 269876L, 270014L,
                                               269095L, 268501L, 268155L, 267625L, 267656L,
                                               267746L, 266742L, 266335L, 266016L, 265347L,
                                               265443L, 265483L, 265531L, 265028L, 265067L,
                                               265104L, 264525L, 264616L, 264762L, 264764L,
                                               264292L, 263740L, 263816L, 263378L, 263405L,
                                               263460L, 263253L, 262574L, 262733L);


        List<Long> questionsWithTag = com.questionsWithTag(tag, begin, end);

       assertEquals("Lista de Tags", questionsWithTagExpected, questionsWithTag);

    }

    /**
     * Método que testa a query 5.
     */
    @Test
    public void getUserInfoTest() throws NoUserIdException {
        Pair<String, List<Long>> usersInfoExpected = new Pair<>(

        "<p>Coder. JS, Perl, Python, Basic<br>Books/movies: SF+F.<br>Dead: "
        + "dell 9300<br>Dead: dell 1720 as of may 10th 2011.</p>"
        + "\n"
        + "\n"
        + "<p>Current system: Acer Aspire 7750G.<br>"
        + "\n"
        + "Works OOTB as of Ubuntu 12.04.<br></p>"
        + "\n",
        Arrays.asList(982507L, 982455L,
        980877L, 980197L, 980189L, 976713L, 974412L, 974359L, 973895L, 973838L));

        Pair<String, List<Long>> usersInfo = new Pair<>("", new ArrayList<>());

        usersInfo = com.getUserInfo(15811);



       assertEquals("Informações Utilizador", usersInfoExpected, usersInfo);

    }

    /**
     * Método que testa a query 6.
     */
    @Test
    public void mostVotedAnswersTest() throws IndexOutOfBoundsException {
        LocalDate begin = LocalDate.of(2015, 11, 1);
        LocalDate end = LocalDate.of(2015, 11,30);
        int N = 5;
        List<Long> maisVotada = new ArrayList<>();
        List<Long> maisVotadaExpected = Arrays.asList(701775L, 697197L, 694560L, 696641L, 704208L);

        maisVotada = com.mostVotedAnswers(N, begin, end);

       assertEquals("Lista de Tags", maisVotadaExpected, maisVotada);

    }

    /**
     * Método que testa a query 7.
     */
    @Test
    public void mostAnsweredQuestionsTest() {
        LocalDate begin = LocalDate.of(2014,8,1);
        LocalDate end = LocalDate.of(2014,8,11);
        int N = 10;
        List<Long> maisRespondida = new ArrayList<>();
        List<Long> maisRespondidaExpected = Arrays.asList(510014L, 510011L, 510009L, 510006L, 510005L,
                                                          510001L, 509992L, 509991L, 509989L, 509983L);

        maisRespondida = com.mostAnsweredQuestions(N, begin, end);

       assertEquals("Mais respondidas", maisRespondidaExpected, maisRespondida);

    }

    /**
     * Método que testa a query 8.
     */
    @Test
    public void containsWordTest() {
        String word = "kde";
        int Nperguntas = 10;

        List<Long> idsPerguntas =  new ArrayList<>();

        List<Long> idsPerguntasExpected = Arrays.asList(980835L, 979082L, 974117L, 974105L,
                                                        973832L, 971812L, 971056L, 968451L,
                                                        964999L, 962770L);

        idsPerguntas = com.containsWord(Nperguntas, word);

        assertEquals("Contem a palavra", idsPerguntasExpected, idsPerguntas);
    }

    /**
     * Método que testa a query 9.
     */
    @Test
    public void bothParticipatedTest() {
        Long id1 = 87L;
        Long id2 = 5691L;
        int NOcorrencias = 10;

        List<Long> idsPerguntas =  new ArrayList<>();

        List<Long> idsPerguntasExpected = Arrays.asList(594L);

        idsPerguntas = com.bothParticipated(NOcorrencias, id1, id2);

        assertEquals("Contem a palavra", idsPerguntasExpected, idsPerguntas);
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
     * Método que testa a query 11.
     */
    @Test
    public void mostUsedBestRepTest() {
        LocalDate begin = LocalDate.of(2013,11,1);
        LocalDate end = LocalDate.of(2013,11,30);
        int N = 5;
        List<Long> result = new ArrayList<>();
        List<Long> resultExpected = Arrays.asList(193L, 163L, 1476L, 6L, 72L);

        result = com.mostUsedBestRep(N, begin, end);

       assertEquals("N tags mais usadas: ", resultExpected, result);
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
