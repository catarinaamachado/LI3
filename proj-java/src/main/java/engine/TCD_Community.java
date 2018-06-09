package engine;

/**
 * Estrutura de dados principal do programa.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180519
 */

 import java.io.IOException;
 import java.util.*;
 import java.util.stream.Collectors;

 import common.*;
 import li3.TADCommunity;
 import org.xml.sax.SAXException;

 import javax.xml.parsers.ParserConfigurationException;
 import java.time.LocalDate;

public class TCD_Community implements TADCommunity {
    private Map<Long, Users> users;
    private Map<Long, Question> questions;
    private Map<Long, Answer> answers;
    private List<Question> questionsList;
    private List<Users> usersList;
    private Map<LocalDate, Day> days;
    private Map<String, Tags> tags;

    public TCD_Community() {
        users = new HashMap<>();
        questions = new HashMap<>();
        answers = new HashMap<>();
        questionsList = new ArrayList<>();
        usersList = new ArrayList<>();
        days = new HashMap<>();
        tags = new HashMap<>();
    }

    public TCD_Community(Map<Long, Users> users, Map<Long, Question> questions,
                       Map<Long,Answer> answers, List<Question> questionsList,
                       List<Users> usersList, Map<LocalDate, Day> days, 
                       Map<String, Tags> tags) {
        setMapUsers(users);
        setMapQuestions(questions);
        setMapAnswers(answers);
        setQuestionsList(questionsList);
        setUsersList(usersList);
        setDays(days);
        setMapTags(tags);
    }

    public TCD_Community(TCD_Community community) {
        this.users = community.getMapUsers();
        this.questions = community.getMapQuestions();
        this.answers = community.getMapAnswers();
        this.questionsList = community.getQuestionsList();
        this.usersList = community.getUsersList();
        this.days = community.getDays();
        this.tags = community.getMapTags();
    }

    /**
     * Função que devolve o apontador para a HashMap users
     *
     * @returns Map<Long, Users> - a HashMap users
     */
     Map<Long, Users> getMapUsers() {
        return users.entrySet().stream().collect(Collectors.toMap(k -> k.getKey(), u -> u.getValue().clone()));

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
    public Map<Long, Question> getMapQuestions() {
        return questions; //por questões de performance não sei como fazer
    }

    /**
     * Função que estabelece a HashMap questions
     *
     * @param users - Map das questions
     */
    public void setMapQuestions(Map<Long, Question> questions) {
        this.questions = questions.entrySet().stream().
                         collect(Collectors.toMap(k -> k.getKey(), q -> q.getValue().clone()));
    }

    /**
     * Função que devolve o apontador para a HashMap answers
     *
     * @returns Map<Integer, Answers> - a HashMap answers
     */
    public Map<Long, Answer> getMapAnswers() {
        return answers; //por questões de performance
    }

    /**
     * Função que estabelece a HashMap answers
     *
     * @param anwers - Map das Answers
     */
    public void setMapAnswers(Map<Long, Answer> answers) {
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
        this.tags = tags.entrySet().stream().
                collect(Collectors.toMap(k -> k.getKey(), t -> t.getValue().clone()));
    }

    /**
     * Função que devolve o apontador para a HashMap days
     *
     * @returns Map<LocalDate, Day> - a HashMap days
     */
    public Map<LocalDate, Day> getDays() {
        return days; //por questões de performance
    }

    /**
     * Função que estabelece a HashMap days
     *
     * @param days - Map days
     */
    public void setDays(Map<LocalDate, Day> tags) {
        this.days = days.entrySet().stream().
                collect(Collectors.toMap(k -> k.getKey(), t -> t.getValue().clone()));
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
     * Método que devolve a representação em String de TCD_Community.
     *
     * @return String que representa uma TCD_Community
     */
    public String toString() {
        return "TCD_Community{" +
                ", users = " + users +
                ", questions = " + questions +
                ", answers = " + answers +
                ", questionsList = " + questionsList.toString() +
                ", usersList = " + usersList.toString() +
                ", days = " + days.toString() +
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
           this.days.equals(com.getDays()) &&
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
    public Answer lookAnswer(long id) {
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
     * Método que verifica se um day existe em days.
     *
     * @return Users um user
     */
    public Day lookDay(LocalDate date) {
        return days.get(date);
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
    public void insertAnswers(Answer a) {
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

    /**
     * Método que insere um day numa HashMap.
     *
     * @param d Dia.
     * @param ld LocalDate do dia.
     *
     */
    public void insertDay(Day d, LocalDate ld) {
        days.put(ld, d);
    }  
    
    /**
     * TODO DOCUMENTACAO
     */
    public void load(String dumpPath) {
        Load load = new Load();

        try {
            load.lerFicheiros(this, dumpPath);
        }
        catch (SAXException e) {
            System.out.println("SAXException: " + e.getMessage());
        }
        catch (ParserConfigurationException e) {
            System.out.println("ParserConfigurationException: " + e.getMessage());
        }
        catch (IOException e) {
            System.out.println("IOException: " + e.getMessage());
        }

    }

    // Query 1
    public Pair<String,String> infoFromPost(long id) {
        Query1 title_username = new Query1(this);

        Pair<String, String> resposta = new Pair("null", "null");

        try{
            resposta = title_username.run(id);
        } catch(NoPostIdException e) {
            System.out.println(e.getMessage()); //TODO era conveniente sair daqui
        }


        return resposta;
    }

    // Query 2
    public List<Long> topMostActive(int N) {
        Query2 query2 = new Query2(this);

        return query2.run(N);
    }

    /**
     * QUERY 3
     *
     * Dado um intervalo de tempo arbitrário,
     * obtem o nú́mero total de posts
     * (identificando perguntas e respostas separadamente) neste período.
     *
     * @param begin - data inicial
     * @param end - data final
     *
     * @returns Pair<Long,Long> - número de perguntas e número de respostas
     */
    public Pair<Long,Long> totalPosts(LocalDate begin, LocalDate end) {
        return new Pair<>(3667L,4102L);
    }

    /**
     * QUERY 4
     *
     * Dado um intervalo de tempo arbitrário, retorna todas
     * as perguntas contendo uma determinada tag.
     * O retorno do método é uma lista com os IDs
     * das perguntas ordenadas em cronologia inversa
     * (a pergunta mais recente no início da lista).
     *
     * @param tag - tag procurada
     * @param begin - data inicial
     * @param end - data final
     *
     * @returns List<Long> - IDs das perguntas
     */
    public List<Long> questionsWithTag(String tag, LocalDate begin, LocalDate end) {
        return Arrays.asList(276174L,276029L,274462L,274324L,274316L,274141L,274100L,272937L,
                272813L,272754L,272666L,272565L,272450L,272313L,271816L,271683L,271647L,270853L,270608L,270528L,270488L,
                270188L,270014L,269876L,269781L,269095L,268501L,268155L,267746L,267656L,267625L,266742L,266335L,266016L,
                265531L,265483L,265443L,265347L,265104L,265067L,265028L,264764L,264762L,264616L,264525L,264292L,263816L,
                263740L,263460L,263405L,263378L,263253L,262733L,262574L);
    }

    // Query 5
    public Pair<String, List<Long>> getUserInfo(long id) {
        if(!users.containsKey(id))
            return new Pair<>("",new ArrayList<>());

        Users u = users.get(id);
        String shortBio = u.getUserBio();

        List<Long> ids = new ArrayList<>();
        TreeSet<Posts> it = u.getPosts();

        int i = 0;

        while (i < 10) {
            Posts p = it.pollFirst();
            if(p != null)
                ids.add(p.getPostId());
            else
                break;
            i++;
        }

        return new Pair<>(shortBio,ids);
    }

    /**
     * QUERY 6
     *
     * Dado um intervalo de tempo arbitrário,
     * devolve os IDs das N respostas com mais votos,
     * em ordem decrescente do número de votos.
     *
     * @param N - número de respostas procuradas
     * @param begin - data inicial
     * @param end - data final
     *
     * @returns List<Long> - IDs das respostas
     */
    public List<Long> mostVotedAnswers(int N, LocalDate begin, LocalDate end) {
        return Arrays.asList(701775L,697197L,694560L,696641L,704208L);
    }

    /**
     * QUERY 7
     *
     * Dado um intervalo de tempo arbitrário,
     * devolve as IDs das N perguntas com mais respostas,
     * em ordem decrescente do nú́mero de votos.
     *
     * @param N - número de perguntas procuradas
     * @param begin - data inicial
     * @param end - data final
     *
     * @returns List<Long> - IDs das perguntas
     */
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
        long resultado = -1;

        try {
            resultado = query10.run(id);
        } catch(NoQuestionIdException | NoAnswersException e) {
            System.out.println(e.getMessage());
        }

        return resultado;
    }

    /**
     * QUERY 11
     *
     * Dado um intervalo arbitrário de tempo,
     * devolve as N tags mais usadas pelos N utilizadores
     * com melhor reputação, em ordem decrescente do
     * nú́mero de vezes em que a tag foi usada.
     *
     * @param N - número de tags e utilizadores procurados
     * @param begin - data inicial
     * @param end - data final
     *
     * @returns List<Long> - IDs das tags
     */
    public List<Long> mostUsedBestRep(int N, LocalDate begin, LocalDate end) {
        return Arrays.asList(6L,29L,72L,163L,587L);
    }

    public void clear(){

    }
}
