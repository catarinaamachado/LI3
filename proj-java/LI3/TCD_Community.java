
/**
 * Escreva a descrição da classe TCD_Community aqui.
 * 
 * @author (seu nome) 
 * @version (número de versão ou data)
 */


import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.stream.Collectors;



public class TCD_Community {
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
      return users; //por questões de performance
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
    
  //TODO EQUALS
    
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
}
