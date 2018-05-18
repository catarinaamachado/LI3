
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
  Map<Integer, Users> users;
  Map<Integer, Questions> questions;
  Map<Integer, Answers> answers;
  List<Questions> questionsList;
  List<Users> usersList;
  //List day;
  Map<String, Tags> tags;

  public TCD_Community() {
        users = new HashMap<>();
        questions = new HashMap<>();
        answers = new HashMap<>();
        questionsList = new ArrayList<>();
        usersList = new ArrayList<>();
        tags = new HashMap<>();
    }
  
  public TCD_Community(Map<Integer, Users> users, Map<Integer, Questions> questions, 
                       Map<Integer,Answers> answers, List<Questions> questionsList, 
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
     * @returns Map<Integer, Users> - a HashMap users
     */
    public Map<Integer, Users>  getMapUsers() {
      return users; //por questões de performance
    }
    
  /**
     * Função que estabelece a HashMap users
     *
     * @param users - Map dos users
     */
    public void setMapUsers(Map<Integer, Users> users) {
        
        this.users = users.entrySet().stream().collect(Collectors.toMap(k -> k.getKey(), u -> u.getValue().clone()));
 
    }
    
  /**
     * Função que devolve o apontador para a HashMap questions
     *
     * @returns Map<Integer, Questions> - a HashMap questions
     */
    public Map<Integer, Questions>  getMapQuestions() {
      return questions; //por questões de performance
    }
    
  /**
     * Função que estabelece a HashMap questions
     *
     * @param users - Map das questions 
     */
    public void setMapQuestions(Map<Integer, Questions> questions) {
        this.questions = questions.entrySet().stream().collect(Collectors.toMap(k -> k.getKey(), q -> q.getValue().clone()));
    }
  
 /**
     * Função que devolve o apontador para a HashMap answers
     *
     * @returns Map<Integer, Answers> - a HashMap answers
     */
    public Map<Integer, Answers>  getMapAnswers() {
      return answers; //por questões de performance
    }
    
 /**
     * Função que estabelece a HashMap answers
     *
     * @param anwers - Map das Answers
     */
    public void setMapAnswers(Map<Integer, Answers> answers) {
        this.answers = answers.entrySet().stream().collect(Collectors.toMap(k -> k.getKey(), a -> a.getValue().clone()));
    }
    
 /**
     * Função que devolve o apontador para o ArrayList questionsList
     *
     * @returns List<Questions> - a lista das perguntas
     */
    public List<Questions> getQuestionsList() {
      return questionsList; //por questões de performance
    }
    
 /**
     * Função que estabelece o apontador para o ArrayList questionsList
     *
     * @param List<Questions> - a lista das perguntas
     */
    public void setQuestionsList(List<Questions> questionsList) {
        this.questionsList = questionsList.stream().
                       map(Questions :: clone).collect(Collectors.toList());
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
    
    
}
