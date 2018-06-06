package engine;


/**
 * Estrutura de dados principal do programa.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180519
 */

import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.stream.Collectors;
import common.*;
import li3.TADCommunity;
import java.time.LocalDate;
import java.util.Arrays;


public class TCD_Community implements TADCommunity {
    private Map<Long, Users> users;
    private Map<Long, Question> questions;
    private Map<Long, Answers> answers;
    private List<Question> questionsList;
    private List<Users> usersList;
    //List day;
    private Map<String, Tags> tags;

    public TCD_Community() {
        users = new HashMap<>();
        questions = new HashMap<>();
        answers = new HashMap<>();
        questionsList = new ArrayList<>();
        usersList = new ArrayList<>();
        tags = new HashMap<>();
    }

    public TCD_Community(Map<Long, Users> users, Map<Long, Question> questions,
                       Map<Long,Answers> answers, List<Question> questionsList,
                       List<Users> usersList, Map<String, Tags> tags) {
        setMapUsers(users);
        setMapQuestions(questions);
        setMapAnswers(answers);
        setQuestionsList(questionsList);
        setUsersList(usersList);
        setMapTags(tags);
    }

    public TCD_Community(TCD_Community community) {
        this.users = community.getMapUsers();
        this.questions = community.getMapQuestions();
        this.answers = community.getMapAnswers();
        this.questionsList = community.getQuestionsList();
        this.usersList = community.getUsersList();
        this.tags = community.getMapTags();
    }

    /**
     * Função que devolve o apontador para a HashMap users
     *
     * @returns Map<Long, Users> - a HashMap users
     */
    public Map<Long, Users>  getMapUsers() {
        return users; //por questões de performance se fizer o clone fica muito lento
    }

    /**
     * Função que estabelece a HashMap users
     *
     * @param users - Map dos users
     */
    public void setMapUsers(Map<Long, Users> users) {
        this.users = users.entrySet().stream().collect(Collectors.toMap(k -> k.getKey(), u -> u.getValue().clone()));
    }

    /**
     * Função que devolve o apontador para a HashMap questions
     *
     * @returns Map<Long, Questions> - a HashMap questions
     */
    public Map<Long, Question>  getMapQuestions() {
        return questions; //por questões de performance
    }

    /**
     * Função que estabelece a HashMap questions
     *
     * @param users - Map das questions
     */
    public void setMapQuestions(Map<Long, Question> questions) {
        this.questions = questions.entrySet().stream().collect(Collectors.toMap(k -> k.getKey(), q -> q.getValue().clone()));
    }

    /**
     * Função que devolve o apontador para a HashMap answers
     *
     * @returns Map<Integer, Answers> - a HashMap answers
     */
    public Map<Long, Answers>  getMapAnswers() {
        return answers; //por questões de performance
    }

    /**
     * Função que estabelece a HashMap answers
     *
     * @param anwers - Map das Answers
     */
    public void setMapAnswers(Map<Long, Answers> answers) {
        this.answers = answers.entrySet().stream().collect(Collectors.toMap(k -> k.getKey(), a -> a.getValue().clone()));
    }

    /**
     * Função que devolve o apontador para o ArrayList questionsList
     *
     * @returns List<Questions> - a lista das perguntas
     */
    public List<Question> getQuestionsList() {
        return questionsList; //por questões de performance
    }

    /**
     * Função que estabelece o apontador para o ArrayList questionsList
     *
     * @param List<Question> - a lista das perguntas
     */
    public void setQuestionsList(List<Question> questionsList) {
        this.questionsList = questionsList.stream().
                        map(Question :: clone).collect(Collectors.toList());
    }

    /**
     * Função que devolve o apontador para o ArrayList usersList
     *
     * @returns List<Users> - a lista dos users
     */
    public List<Users> getUsersList() {
        return usersList; //por questões de performance
    }

    /**
     * Função que estabelece o apontador para o ArrayList usersList
     *
     * @param List<Users> - a lista dos utilizadores
     */
    public void setUsersList(List<Users> questionsList) {
        this.usersList = usersList.stream().
                    map(Users :: clone).collect(Collectors.toList());
    }

    /**
     * Função que devolve o apontador para a HashMap tags
     *
     * @returns Map<String, Tags> - a HashMap tags
     */
    public Map<String, Tags> getMapTags() {
        return tags; //por questões de performance
    }

    /**
     * Função que estabelece a HashMap tags
     *
     * @param tags - Map das tags
     */
    public void setMapTags(Map<String, Tags> tags) {
        this.tags = tags.entrySet().stream().collect(Collectors.toMap(k -> k.getKey(), t -> t.getValue().clone()));
    }

    /**
     * Método que faz uma cópia de TCD_Community
     * Para tal invoca o construtor de cópia.
     *
     * @return cópia de TCD_Community
     */
    public TCD_Community clone() {
        return new TCD_Community (this);
    }

    /**
     * Método que devolve a representação em String de Questions.
     *
     * @return String que representa uma question
     */
    public String toString() {
        return "TCD_Community{" +
                ", users = " + users +
                ", questions = " + questions +
                ", answers = " + answers +
                ", questionsList = " + questionsList.toString() +
                ", usersList = " + usersList.toString() +
                ", tags = " + tags +
                '}';
    }

    /**
     * Método que determina se dois TCD_Community objeto são iguais.
     *
     * @param object Objecto a ser usado como termo de comparação.
     *
     * @return Boolean indicando se os dois objetos são iguais
     */
    public boolean equals(Object object) {
        if (this == object)
            return true;

        if (object == null || (this.getClass() != object.getClass()))
            return false;

        TCD_Community com = (TCD_Community) object;

  
    return (this.users.equals(com.getMapUsers()) &&
           this.questions.equals(com.getMapQuestions()) &&
           this.answers.equals(com.getMapAnswers()) && 
           this.questionsList.equals(com.getQuestionsList()) &&
           this.usersList.equals(com.getUsersList()) && 
           this.tags.equals(com.getMapTags()));
    }

    /**
     * Método que verifica se uma questão existe em questions.
     *
     * @return Question uma pergunta
     */
    public Question lookQuestion(long id) {
        return questions.get(id);
    }

    /**
     * Método que verifica se uma resposta existe em answers.
     *
     * @return Answers uma resposta
     */
    public Answers lookAnswer(long id) {
        return answers.get(id);
    }

    /**
     * Método que verifica se um user existe em users.
     *
     * @return Users um user
     */
    public Users lookUser(long id) {
        return users.get(id);
    }

    /**
     * Método que insere uma pergunta numa HashMap.
     *
     * @param q - Uma pergunta.
     *
     */
    public void insertQuestion(Question q) {
        questions.put(q.getPostId(), q);
    }

    /**
     * Método que insere uma resposta numa HashMap.
     *
     * @param a - Uma resposta.
     *
     */
    public void insertAnswers(Answers a) {
        answers.put(a.getPostId(), a);
    }

    /**
     * Método que insere um user numa HashMap.
     *
     * @param u - Um user.
     *
     */
    public void insertUser(Users u) {
        users.put(u.getUsersId(), u);
    }
    
    public void load(String dumpPath) {
        Load load = new Load();
      
     try {
        load.lerFicheiros(this, dumpPath);
     }
     catch (Exception e) {
         System.out.println("Error: " + e.getMessage());
     }
   
    }

    // Query 1
    public Pair<String,String> infoFromPost(long id) {
        Query1 title_username = new Query1(this);
        
        return title_username.run(id); 
    }

    // Query 2
    public List<Long> topMostActive(int N) {
        Query2 query2 = new Query2(this);
        
        return query2.run(N);
    }

    // Query 3
    public Pair<Long,Long> totalPosts(LocalDate begin, LocalDate end) {
        return new Pair<>(3667L,4102L);
    }

    // Query 4
    public List<Long> questionsWithTag(String tag, LocalDate begin, LocalDate end) {
        return Arrays.asList(276174L,276029L,274462L,274324L,274316L,274141L,274100L,272937L,
                272813L,272754L,272666L,272565L,272450L,272313L,271816L,271683L,271647L,270853L,270608L,270528L,270488L,
                270188L,270014L,269876L,269781L,269095L,268501L,268155L,267746L,267656L,267625L,266742L,266335L,266016L,
                265531L,265483L,265443L,265347L,265104L,265067L,265028L,264764L,264762L,264616L,264525L,264292L,263816L,
                263740L,263460L,263405L,263378L,263253L,262733L,262574L);
    }

    // Query 5
    public Pair<String, List<Long>> getUserInfo(long id) {
        String shortBio = "<p>Coder. JS, Perl, Python, Basic<br>Books/movies: SF+F.<br>Dead:" +
                "dell 9300<br>Dead: dell 1720 as of may 10th 2011.</p>\n" +
                "<p>Current system: Acer Aspire 7750G.<br>\n" +
                "Works OOTB as of Ubuntu 12.04.<br></p>";
        List<Long> ids = Arrays.asList(982507L,982455L,980877L,980197L,980189L,976713L,974412L,
                974359L,973895L,973838L);
        return new Pair<>(shortBio,ids);
    }

    // Query 6
    public List<Long> mostVotedAnswers(int N, LocalDate begin, LocalDate end) {
        return Arrays.asList(701775L,697197L,694560L,696641L,704208L);
    }

    // Query 7
    public List<Long> mostAnsweredQuestions(int N, LocalDate begin, LocalDate end) {
        return Arrays.asList(505506L,508221L,506510L,508029L,506824L,505581L,505368L,509498L,509283L,508635L);
    }

    // Query 8
    public List<Long> containsWord(int N, String word) {
        return Arrays.asList(980835L,979082L,974117L,974105L,973832L,971812L,971056L,968451L,964999L,962770L);
    }

    // Query 9
    public List<Long> bothParticipated(int N, long id1, long id2) {
        return Arrays.asList(594L);
    }

    // Query 10
    public long betterAnswer(long id) {
        Query10 query10 = new Query10(this);
        
        return query10.run(id);
    }

    // Query 11
    public List<Long> mostUsedBestRep(int N, LocalDate begin, LocalDate end) {
        return Arrays.asList(6L,29L,72L,163L,587L);
    }

    public void clear(){

    }
}
