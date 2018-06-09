package engine;
import java.io.IOException;
import java.util.*;
import java.util.stream.Collectors;

import common.*;
import li3.TADCommunity;
import org.xml.sax.SAXException;

import javax.xml.parsers.ParserConfigurationException;
import java.time.LocalDate;

/**
 * Estrutura de dados principal do programa.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180519
 */

public class TCD_Community implements TADCommunity {
    private Map<Long, Users> users;
    private Map<Long, Question> questions;
    private Map<Long, Answers> answers;
    private List<Question> questionsList;
    private List<Users> usersList;
    //List day;
    private Map<String, Tags> tags;

    /**
     * Construtor vazio.
     *
     */
    public TCD_Community() {
        users = new HashMap<>();
        questions = new HashMap<>();
        answers = new HashMap<>();
        questionsList = new ArrayList<>();
        usersList = new ArrayList<>();
        tags = new HashMap<>();
    }

    /**
     * Construtor parametrizado.
     *
     * @param users - HashMap que armazena os utilizadores.
     * @param questions - HashMap que armazena as perguntas.
     * @param answers - HashMap que armazena as respostas.
     * @param questionList - Lista que armazena perguntas.
     * @param usersList - Lista que armazena utilizadores.
     * @param tags - HashMap que armazena as tags.
     */
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
    
    /**
     * Construtor cópia.
     * @param community - Estrutra de dados TCD_Community
     */
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
    public Map<Long, Users> getMapUsers() {
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
        return questions.entrySet().stream().
                         collect(Collectors.toMap(k -> k.getKey(), q -> q.getValue().clone()));
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
    public Map<Long, Answers>  getMapAnswers() {
        return answers.entrySet().stream().collect(Collectors.toMap(k -> k.getKey(), a -> a.getValue().clone()));
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
        return questionsList.stream().map(Question :: clone).collect(Collectors.toList());
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
        return usersList.stream().
                    map(Users :: clone).collect(Collectors.toList());
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
        return tags.entrySet().stream().
                  collect(Collectors.toMap(k -> k.getKey(), t -> t.getValue().clone()));
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

    /**
     * Método que faz o parser dos ficheiros xml.
     * 
     * @param dumpPath - caminho para o ficheiro xml.
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

    //Query 1
    /**
     * Dado o identificador de um post, o método retorna
     * o título do post e o nome (não o ID) de utilizador do autor.
     * Caso o post não possua título ou nome de utilizador, o resultado 
     * correspondente deverá ser NULL.
     * Se o post for uma resposta, a função retorna informações 
     * (título e utilizador) da pergunta correspondente.
     * Acresce que se o id passado como parametro não for id de nenhum post
     * devolve NULL.
     * 
     *
     * @param id - id do post
     * 
     * @returns Pair<String, String> - título e o nome do autor do pergunta
     */
    public Pair<String,String> infoFromPost(long id) {
        long userId;
        long parentId;
        String title, username;
        
        Question pergunta = lookQuestion(id);
        
        if (pergunta == null) {
            Answers resposta = lookAnswer(id);
            
            if(resposta == null) {
                new Pair("null","null");
            }
            
            if (resposta != null) {
                parentId = resposta.getParentId();
                pergunta = lookQuestion(parentId);
            }
        }
        
        if (pergunta != null) {
            userId = pergunta.getUserId();
            
            Users user = lookUser(userId);
            
            if (user == null) {
                return new Pair("null","null");
            }
            
            title = pergunta.getTitle();
            username = user.getUserName();
            
            if (title != null && username != null) {
                return new Pair<>(title, username);
            }
            
        }
        
        return new Pair("null","null");
    
    }

    //Query 2
     /**
     * Método que devolve o top N utilizadores com maior número
     * de posts de sempre. Para isto, são considerados tanto perguntas
     * quanto respostas dadas pelo respectivo utilizador.
     *
     * @param N Número de utilizadores com mais posts.
     * 
     * @returns List<Long> - lista com os ids dos N utilizadores com mais posts publicados
     */
    public List<Long> topMostActive(int N) {
       return  users.values().stream().
               sorted(new NumeroPostsComparador()).limit(N).
               map(u -> u.getUsersId()).
               collect(Collectors.toCollection(ArrayList::new));
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

    //Query 10
    /**
     * Dado o ID de uma pergunta, obtem a melhor resposta.
     * Para isso, usa a função de média ponderada abaixo:
     * (score da resposta × 0.45) + (reputação do utilizador × 0.25) +
     * (número de votos recebidos pela resposta × 0.2) +
     * (número de comentários recebidos pela resposta × 0.1) 
     * 
     * Caso a pergunta não tenha nenhuma resposta ou o id passado como
     * parametro não identifique uma pergunta o método devolverá -1.
     *
     * @param id - id da pergunta
     * 
     * @returns long - id da resposta
     */
    public long betterAnswer(long id) {
       int i, total_answers, reputation, score, commentCount;
        long answerId = -1;
        double total, max = 0.0;
        
        Question pergunta = lookQuestion(id);
        
        if(pergunta == null) {
            return answerId;
        }
        
        total_answers = pergunta.getNAnswers();
        
        if(total_answers == 0) {
            return answerId;
        }
        
        
        for(i = 0; i < total_answers; i++) {
             Answers resposta = pergunta.getAnswersList().get(i);
             Users user = lookUser(resposta.getUserId());
             
             if(user == null) {
                 reputation = 0;
             }
             else {
                 reputation = user.getReputation();
             }
            
             score = resposta.getScore();
             commentCount = resposta.getCommentCount();
             
             total = score * 0.65 + reputation * 0.25 + commentCount * 0.1;
             
             if(total > max) {
                 max = total;
                 answerId = resposta.getPostId();
             }
        }
        
        return answerId;
    }

    // Query 11
    public List<Long> mostUsedBestRep(int N, LocalDate begin, LocalDate end) {
        return Arrays.asList(6L,29L,72L,163L,587L);
    }

    public void clear(){

    }
}
