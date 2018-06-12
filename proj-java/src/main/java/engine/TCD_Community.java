package engine;

/**
 * Estrutura de dados principal do programa.
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180519
 */

 import java.util.*;
 import java.util.stream.Collectors;
 import java.util.function.Supplier;

 import common.*;
 import li3.TADCommunity;
 
 import org.xml.sax.SAXException;
 import java.io.IOException;
 import javax.xml.parsers.ParserConfigurationException;
 
 import java.time.LocalDate;

public class TCD_Community implements TADCommunity {
    private Map<Long, Users> users;
    private Map<Long, Posts> posts;
    private Set<Question> questionsSet;
    private Set<Users> usersSet;
    private List<Long> usersPostList;
    private Map<LocalDate, Day> days;
    private Map<String, Long> tags;

    /**
     * Construtor vazio.
     *
     */
    public TCD_Community() {
        users = new HashMap<>();
        posts = new HashMap<>();
        questionsSet = null;
        usersSet = null;
        usersPostList = null;
        days = new HashMap<>();
        tags = new HashMap<>();
    }

    /**
     * Construtor parametrizado.
     *
     * @param users - HashMap que armazena os utilizadores.
     * @param posts - HashMap que armazena os posts.
     * @param questionsSet - Set que armazena perguntas.
     * @param usersSet - Set que armazena utilizadores.
     * @param usersPostList - Lista que armazena os identificadors dos Users.
     * @param tags - HashMap que armazena as tags.
     */
    public TCD_Community(Map<Long, Users> users, Map<Long, Posts> posts,
                       Set<Question> questionsSet,Set<Users> usersSet, 
                       List<Long> usersPostList, Map<LocalDate, 
                       Day> days, Map<String, Long> tags) {
        setMapUsers(users);
        setMapPosts(posts);
        setQuestionsSet(questionsSet);
        setUsersSet(usersSet);
        setUsersPostList(usersPostList);
        setDays(days);
        setMapTags(tags);
    }

    /**
     * Construtor cópia.
     * @param community - Estrutra de dados TCD_Community
     */
    public TCD_Community(TCD_Community community) {
        this.users = community.getMapUsers();
        this.posts = community.getMapPosts();
        this.questionsSet = community.getQuestionsSet();
        this.usersSet = community.getUsersSet();
        this.usersPostList = community.getUsersPostList();
        this.days = community.getDays();
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
     * Função que devolve o apontador para a HashMap posts
     *
     * @returns Map<Long, Posts> - a HashMap posts
     */
    public Map<Long, Posts> getMapPosts() {
        return posts.entrySet().stream().
                         collect(Collectors.toMap(k -> k.getKey(), q -> q.getValue().clone()));
    }

    /**
     * Função que estabelece a HashMap posts
     *
     * @param posts - Map das posts
     */
    public void setMapPosts(Map<Long, Posts> posts) {
        this.posts = posts.entrySet().stream().
                         collect(Collectors.toMap(k -> k.getKey(), q -> q.getValue().clone()));
    }

    /**
     * Função que devolve o apontador para o Set questionsSet
     *
     * @returns Set<Questions> - o set das perguntas
     */
    public Set<Question> getQuestionsSet() {
        return questionsSet.stream().map(Question :: clone).collect(Collectors.toSet());
    }

    /**
     * Função que estabelece o apontador para o Set questionsSet
     *
     * @param questionsSet - o set das perguntas
     */
    public void setQuestionsSet(Set<Question> questionsSet) {
        this.questionsSet = questionsSet.stream().
                        map(Question :: clone).collect(Collectors.toSet());
    }

    /**
     * Função que devolve o apontador para o Set usersSet
     *
     * @returns Set<Users> - o set dos users
     */
    public Set<Users> getUsersSet() {
        return usersSet.stream().
                    map(Users :: clone).collect(Collectors.toSet());
    }

    /**
     * Função que estabelece o apontador para o Set usersSet
     *
     * @param usersSet - set dos utilizadores
     */
    public void setUsersSet(Set<Users> usersSet) {
        this.usersSet = usersSet.stream().
                    map(Users :: clone).collect(Collectors.toSet());
    }
    
    /**
     * Função que devolve o apontador para a lista de usersPostList.
     *
     * @returns List<Long> - lista com os ids dos users.
     */
    public List<Long> getUsersPostList() {
        return usersPostList.stream().collect(Collectors.toCollection(ArrayList :: new));
    }

    /**
     * Função que estabelece o apontador para a lista de usersPostList.
     *
     * @param usersPostList- lista dos ids dos utilizadores
     */
    public void setUsersPostList(List<Long> usersPostList) {
        this.usersPostList = usersPostList.stream().collect(Collectors.toList());
    }
    
    /**
     * Função que devolve o apontador para a HashMap tags
     *
     * @returns Map<String, Long> - a HashMap tags
     */
    public Map<String, Long> getMapTags() {
        return tags.entrySet().stream().
                  collect(Collectors.toMap(k -> k.getKey(), t -> t.getValue()));
    }
    
    /**
     * Função que estabelece a HashMap tags
     *
     * @param tags - Map das tags
     */
    public void setMapTags(Map<String, Long> tags) {
        this.tags = tags.entrySet().stream().
                collect(Collectors.toMap(k -> k.getKey(), t -> t.getValue()));
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
    public void setDays(Map<LocalDate, Day> days) {
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
                ", posts = " + posts +
                ", questionsSet = " + questionsSet.toString() +
                ", usersSet = " + usersSet.toString() +
                ", usersPostList = " + usersPostList.toString() +
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
           this.posts.equals(com.getMapPosts()) &&
           this.questionsSet.equals(com.getQuestionsSet()) &&
           this.usersSet.equals(com.getUsersSet()) &&
           this.days.equals(com.getDays()) &&
           this.tags.equals(com.getMapTags()));
    }

    /**
     * Método que verifica se um post existe em posts.
     *
     * @return Posts um post
     */
    public Posts lookPost(long id) {
        return posts.get(id);
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
     * Método que insere um post na HashMap posts.
     *
     * @param p - Um post.
     *
     */
    public void insertPost(Posts p) {
        posts.put(p.getPostId(), p);
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
     * Método que insere uma tag numa HashMap.
     *
     * @param name_tag - nome da Tag.
     * @param id_tag - identificador da Tag.
     *
     */
    public void insertTag(String name_tag, long id_tag) {
        tags.put(name_tag, id_tag);
    }

    /**
     * Método que preenche o questionsSet (de perguntas) ordenado por data.
     *
     */
    public void initQSet() {
        if (questionsSet == null) {
            
            Supplier<TreeSet<Question>> supplier = () -> new TreeSet<Question>(new PostComparator());
                
            questionsSet = posts.values().stream().filter(p -> (p.getPostType() == 1)).map( p -> (Question)p).
                           collect(Collectors.toCollection(supplier));
        }
    }
   
    /**
     * Método que preenche o usersSet (de users) ordenado por reputação.
     *
     */
    public void initUSet() {
        if (usersSet == null) {
            usersSet = new TreeSet<>(new UsersComparator());

            Iterator<Users> it = users.values().iterator();
            while (it.hasNext())
                usersSet.add(it.next());
        }
    }
    
    /**
     * Método que preenche o usersPostsList (de identificadores de users) ordenado por número de posts.
     *
     */
    public void initUsersPostsList() {
        if (usersPostList == null) {
              usersPostList = users.values().stream().
              sorted(new NumeroPostsComparador()).
              map(u -> u.getUsersId()).
              collect(Collectors.toCollection(ArrayList::new));
        }
    }
    
    /**
     * Método que faz o parser dos ficheiros xml.
     *
     * @param dumpPath - caminho para o ficheiro xml.
     */
    public void load(String dumpPath) throws SAXException, ParserConfigurationException, IOException {
        Load load = new Load();

        load.lerFicheiros(this, dumpPath);
 
    }

    /**
     * QUERY 1
     * 
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
     * 
     * @throws NoPostIdException
     */
    public Pair<String,String> infoFromPost(long id) throws NoPostIdException {
        long userId;
        long parentId;
        String title, username;
        Answer resposta = null;
        Question pergunta = null;

        Posts post = lookPost(id);
        
        if(post == null) {
                throw new NoPostIdException(id + " não identifica uma pergunta nem uma resposta");
            }

        if (post.getPostType() == 2) {
                resposta = (Answer) post;
                parentId = resposta.getParentId();
                pergunta = (Question) lookPost(parentId); 
        }
        else {
                pergunta = (Question) post;
        }
 
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

        
        return new Pair("null","null");
    }

    /**
     * QUERY 2
     * 
     * Método que devolve o top N utilizadores com maior número
     * de posts de sempre. Para isto, são considerados tanto perguntas
     * quanto respostas dadas pelo respectivo utilizador.
     *
     * @param N Número de utilizadores com mais posts.
     *
     * @returns List<Long> - lista com os ids dos N utilizadores com mais posts publicados
     */
    public List<Long> topMostActive(int N) {
        initUsersPostsList();
        
        return usersPostList.stream().limit(N).collect(Collectors.toCollection(ArrayList::new));
        
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
        long number_q = 0;
        long number_p = 0;
        Day d;
        
        if(begin.isBefore(end.plusDays(1))){
            while(!begin.equals(end.plusDays(1))){
                d = days.get(begin);
                
                if(d != null){
                    number_q += d.getN_questions();
                    number_p += d.getN_answers();
                }
                
                begin = begin.plusDays(1);
            }
        }
        
        return new Pair<Long, Long>(number_q, number_p);
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
        List resp = new ArrayList<>();
        Day d;
        
        if(begin.isBefore(end.plusDays(1))){        
            while(!end.equals(begin.plusDays(-1))){
                d = days.get(end);
                
                if(d != null){
                    for(Question q: d.getQuestions()){
                        if(q.getTags().contains(tag))
                            resp.add(q.getPostId());
                    }
                }
                
                end = end.plusDays(-1);
            }
        }
        
        return resp;
    }

    /**
     * QUERY 5
     *
     * Dado um ID de utilizador, devolver a informação do
     * seu perfil (short bio) e os IDs dos seus 10 últimos posts,
     * ordenados por cronologia inversa;
     *
     * @param id - User id
     *
     * @returns List<Long> - IDs das perguntas
     */
    public Pair<String, List<Long>> getUserInfo(long id) throws NoUserIdException {
        if(!users.containsKey(id))
            throw new NoUserIdException(Long.toString(id));

        Users u = users.get(id);
        String shortBio = u.getUserBio();

        List<Long> ids = u.getPosts()
                .stream()
                .sorted(new PostComparator())
                .limit(10)
                .map(q -> q.getPostId())
                .collect(Collectors.toList());

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
    public List<Long> mostVotedAnswers(int N, LocalDate begin, LocalDate end) throws IndexOutOfBoundsException {
       List as = new ArrayList<Answer>();
       List<Long> ids = new ArrayList<>();
       Day d;
        
       if(begin.isBefore(end.plusDays(1))){
            while(!begin.equals(end.plusDays(1))){
                d = days.get(begin);
                
                if(d != null){
                    for(Answer a: d.getAnswers())
                        as.add(a);     
                }
                
                begin = begin.plusDays(1);
            }
        }    
        else
            return as;
          
       as.sort(new NumeroVotosRespostas());
       as = as.subList(0, N);
       
       Iterator<Answer> it = as.iterator();
       
       while (it.hasNext()) {
            Answer a = it.next();
            ids.add(a.getPostId());
       }

       return ids;
    }

    /**
     * QUERY 7
     *
     * Dado um intervalo de tempo arbitrário,
     * devolve as IDs das N perguntas com mais respostas,
     * em ordem decrescente do nú́mero de respostas.
     *
     * @param N - número de perguntas procuradas
     * @param begin - data inicial
     * @param end - data final
     *
     * @returns List<Long> - IDs das perguntas
     */
    public List<Long> mostAnsweredQuestions(int N, LocalDate begin, LocalDate end) {
       List qs = new ArrayList<Question>();
       List<Long> ids = new ArrayList<>();
       Day d;
        
       if(begin.isBefore(end.plusDays(1))){
            while(!begin.equals(end.plusDays(1))){
                d = days.get(begin);
                
                if(d != null){
                    for(Question q: d.getQuestions())
                        qs.add(q);     
                }
                    
                begin = begin.plusDays(1);
            }
        }    
        else
            return qs;
          
       qs.sort(new NumeroRespostasPergunta());
       qs = qs.subList(0, N);
       
       Iterator<Question> it = qs.iterator();
       
       while (it.hasNext()) {
            Question q = it.next();
            ids.add(q.getPostId());
       }

       return ids;
    }

    /**
     * QUERY 8
     *
     * Dado uma palavra, devolver uma lista com os IDs de
     * N perguntas cujos títulos a contenham, ordenados por cronologia inversa
     *
     * @param N - número de perguntas
     * @param word - palavra a verificar
     *
     * @return List<Long> - IDs das perguntas
     */
    public List<Long> containsWord(int N, String word) {
        initQSet();

        return questionsSet
                .stream()
                .filter(q -> q.getTitle().contains(word))
                .limit(N)
                .map(Question::getPostId)
                .collect(Collectors.toList());
    }

    private boolean participateAnswers(Question q, long id) {
        return q.getAnswers()
                .stream()
                .anyMatch(quest -> quest.getUserId() == id);
    }

    /**
     * QUERY 9
     *
     * Dados os IDs de dois utilizadores, devolver as últimas
     * N perguntas (cronologia inversa) em que participaram dois utilizadores
     * específicos.
     *
     * @param N - número de ocorrências
     * @param id1 - utilizador 1
     * @param id2 - utilizador 2
     *
     * @return List<Long> - IDs das perguntas
     */
    public List<Long> bothParticipated(int N, long id1, long id2) {
        initQSet();

        List<Long> ret = new ArrayList<>(N);
        boolean id1P, id2P;
        long uid;

        Iterator<Question> it = questionsSet.iterator();

        for (int i = 0; i < N && it.hasNext();) {
            Question q = it.next();

            uid = q.getUserId();

            if(uid == id1)
                id1P = true;
            else
                id1P = participateAnswers(q, id1);

            if(id1P) {
                if(uid == id2)
                    id2P = true;
                else
                    id2P = participateAnswers(q, id2);

                if(id2P) {
                    ret.add(q.getPostId());
                    i++;
                }
            }
        }

        return ret;
    }

    /**
     * QUERY 10
     * 
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
     * 
     * @throws NoAnswersException, NoQuestionIdException 
     */
    public long betterAnswer(long id) throws NoAnswersException, NoQuestionIdException {
        int i, total_answers, reputation, score, commentCount;
        long answerId = -1;
        double total, max = 0.0;
        Question pergunta;
        Answer resposta;

        Posts post = lookPost(id);

        if(post == null || (post.getPostType() != 1)) {
            throw new NoQuestionIdException("O id " + id + " não pertence a uma pergunta.");
        }
        
        pergunta = (Question)post;
        
        total_answers = pergunta.getNAnswers();
        
        if(total_answers == 0) {
            throw new NoAnswersException("A pergunta não tem nenhuma resposta.");
            }

        for(i = 0; i < total_answers; i++) {
             resposta = pergunta.getAnswers().get(i);
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
     * @returns List<Long> - Identificadores das tags
     * @throws IllegalArgumentException, IndexOutOfBoundsException
     */
    public List<Long> mostUsedBestRep(int N, LocalDate begin, LocalDate end) throws IllegalArgumentException, IndexOutOfBoundsException {
        initUSet();
        List<Long> ident_tags = new ArrayList<>();
        List<Question> qs = new ArrayList<Question>();
        Day d;
        Map<Long, Users> users_rep = usersSet.stream()
                                        .limit(N)
                                        .collect(Collectors.toMap(u -> u.getUsersId(), u -> u));      
       
       if(begin.isBefore(end.plusDays(1))){
            while(!begin.equals(end.plusDays(1))){
                d = days.get(begin);
                
                if(d != null){
                    for(Question q: d.getQuestions()){
                        if(users_rep.get(q.getUserId()) != null){
                            String tag = q.getTags();
                            String[] parts = tag.split("[><]");
                        
                            for(int i = 1; i < parts.length; i++){
                                if(tags.get(parts[i]) != null)     
                                    ident_tags.add(tags.get(parts[i]));
                                i++;
                            }   
                        }
                    }   
                }
                
                begin = begin.plusDays(1);
            }
        }    
        else
            return ident_tags;       
       
       Map<Long, Long> maptags =
            ident_tags.stream().collect(Collectors.groupingBy(e -> e, Collectors.counting()));
            
       return maptags.entrySet().stream()
                 .sorted(Map.Entry.comparingByValue(Comparator.reverseOrder()))
                 .map(Map.Entry::getKey)
                 .collect(Collectors.toList()).subList(0,N);                   
    }

    public void clear(){

    }
}
