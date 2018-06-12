package li3;

/**
 * Graphical User Interface
 *
 * @author A81047
 * @author A34900
 * @author A82339
 * @version 20180611
 */

import engine.TCD_Community;
<<<<<<< HEAD
import java.time.LocalDate;
import java.time.Month;
import common.NoPostIdException;
import common.NoAnswersException;
import common.NoQuestionIdException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import common.Pair;

import javafx.application.Application;
import static javafx.geometry.HPos.RIGHT;
=======

import common.NoPostIdException;
import common.NoAnswersException;
import common.NoQuestionIdException;
import common.Pair;
import java.io.IOException;
import org.xml.sax.SAXException;
import javax.xml.parsers.ParserConfigurationException;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

import javafx.application.Application;
>>>>>>> cbf6d32b5392f7fb5546343d3c1fd3e39cd57db3
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.application.Platform;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
<<<<<<< HEAD
import javafx.scene.shape.Line;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.control.MenuButton;
import javafx.scene.control.CheckMenuItem;
import javafx.event.EventHandler;
import javafx.event.ActionEvent;
import javafx.scene.control.MenuItem;
import javafx.scene.control.TableCell;
import javafx.util.Callback;
import javafx.scene.control.Alert.AlertType;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.math.BigDecimal;
import org.xml.sax.SAXException;
import javax.xml.parsers.ParserConfigurationException;
import java.io.IOException;
=======
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
>>>>>>> cbf6d32b5392f7fb5546343d3c1fd3e39cd57db3
import javafx.scene.text.TextFlow;
import javafx.scene.text.TextAlignment;

public class GUI extends Application {
    private Stage screen;
    private Scene main, queries, query1, query2, query3, query4, 
                        query5, query6, query7, query8, query9, query10, query11;
    private String nome_utilizador;
    private static TCD_Community qe;
    private long before;
    private long after;
    private long time_load;

    private void loadQuery11() {
        GridPane grid = new GridPane();
        grid.setAlignment(Pos.TOP_CENTER);
        grid.setHgap(20);
        grid.setVgap(20);
        grid.setPadding(new Insets(25, 25, 25, 25));

        Label query = new Label("Query 11");
        grid.add(query, 1, 2);
        query.setTextFill(Color.web("#0076a3"));
        query.setFont(new Font(28));
        query.setMaxWidth(Double.MAX_VALUE);
        query.setAlignment(Pos.TOP_LEFT);
        
        Label nome = new Label("Insira um número:");
        grid.add(nome, 1, 5);

        TextField nomeField = new TextField();
        grid.add(nomeField, 2, 5);
        
        final DatePicker dataField1 = new DatePicker();
        dataField1.setPromptText("Data inicial");
        grid.add(dataField1, 1, 7);

        final DatePicker dataField2 = new DatePicker();
        dataField2.setPromptText("Data final");
        grid.add(dataField2, 2, 7);
                
        Button resultado = new Button("Obter resultado");
        HBox hbresultado = new HBox(10);
        hbresultado.setAlignment(Pos.BOTTOM_RIGHT);
        hbresultado.getChildren().add(resultado);
        grid.add(hbresultado, 2, 8);
        
        resultado.setOnAction(e -> {
            before = System.currentTimeMillis();
            int n = Integer.parseInt(nomeField.getText());
            
            List<Long> q11 = new ArrayList<>();
            try {
                q11 = qe.mostUsedBestRep(n, 
                          LocalDate.parse(dataField1.getValue().toString()),
                          LocalDate.parse(dataField2.getValue().toString())); 
                    
                TextFlow flowqr1 = new TextFlow();
                Text title = new Text("IDs das " + n + " tags mais usadas pelos " + n + 
                                      " users com melhor rep: ");
                title.setFont(Font.font("Verdana", FontWeight.BOLD, 13));
                title.setTextAlignment(TextAlignment.JUSTIFY);
                Text titleR1 = new Text(q11.toString());
                titleR1.setTextAlignment(TextAlignment.JUSTIFY);
                flowqr1.getChildren().addAll(title, titleR1);
                flowqr1.setMaxHeight(2000);
                flowqr1.setMaxWidth(190);
                grid.add(flowqr1, 1, 11);                
            } catch (IllegalArgumentException a) {

            } catch (IndexOutOfBoundsException a) {

            } catch (Exception error) {
            }
            
            after = System.currentTimeMillis();
            
            Label q1T = new Label("Takes: " + (after-before) + " ms");
            grid.add(q1T, 1, 13);  
        });
        
        
        Button limpar = new Button("Limpar");
        HBox hblimpar = new HBox(10);
        hblimpar.setAlignment(Pos.BOTTOM_RIGHT);
        hblimpar.getChildren().add(limpar);
        grid.add(hblimpar, 3, 8);

        limpar.setOnAction(e -> {
            loadQuery11();
            screen.setScene(this.query11);
        });

                    
        Button voltar = new Button("Voltar");
        HBox hbVoltar = new HBox(10);
        hbVoltar.setAlignment(Pos.BOTTOM_LEFT);
        hbVoltar.getChildren().add(voltar);
        grid.add(hbVoltar, 8, 13);

        voltar.setOnAction(e -> {
            loadQueries();
            screen.setScene(this.queries);
        });

        this.query11 = new Scene(grid, 800, 600);
    }
    private void loadQuery10() {
        GridPane grid = new GridPane();
        grid.setAlignment(Pos.TOP_CENTER);
        grid.setHgap(20);
        grid.setVgap(20);
        grid.setPadding(new Insets(25, 25, 25, 25));

        Label query = new Label("Query 10");
        grid.add(query, 0, 2);
        query.setTextFill(Color.web("#0076a3"));
        query.setFont(new Font(28));
        query.setMaxWidth(Double.MAX_VALUE);
        query.setAlignment(Pos.TOP_LEFT);
        
        Label nome = new Label("Insira um nº de uma pergunta:");
        grid.add(nome, 0, 5);

        TextField nomeField = new TextField();
        grid.add(nomeField, 1, 5);
        
        Button resultado = new Button("Obter resultado");
        HBox hbresultado = new HBox(10);
        hbresultado.setAlignment(Pos.BOTTOM_RIGHT);
        hbresultado.getChildren().add(resultado);
        grid.add(hbresultado, 1, 8);
        
        resultado.setOnAction(e -> {
            long n = Long.parseLong(nomeField.getText());
            before = System.currentTimeMillis();            
            try {
                long q10 = qe.betterAnswer(n);
                
                Text title = new Text("A melhor resposta a essa pergunta é: ");
                title.wrappingWidthProperty().set(215);
                title.setFont(Font.font("Verdana", FontWeight.BOLD, 13));
                title.setTextAlignment(TextAlignment.JUSTIFY);
                grid.add(title, 1, 11);  
                
                Text titleR1 = new Text(Long.toString(q10));
                titleR1.wrappingWidthProperty().set(200);                
                titleR1.setTextAlignment(TextAlignment.JUSTIFY);
                grid.add(titleR1, 1, 12);
                
            } catch (NoQuestionIdException a) {
                Text q1T = new Text(a.getMessage());
                q1T.wrappingWidthProperty().set(190);
                grid.add(q1T, 1, 12);                 
            } catch (NoAnswersException a) {
                Text q1T = new Text(a.getMessage());
                q1T.wrappingWidthProperty().set(190);
                grid.add(q1T, 1, 12);    
            } catch (Exception error) {
            }
            
            after = System.currentTimeMillis();
            
            Label qT = new Label("Takes: " + (after-before) + " ms");
            grid.add(qT, 1, 13);  
        });
        
        
        Button limpar = new Button("Limpar");
        HBox hblimpar = new HBox(10);
        hblimpar.setAlignment(Pos.BOTTOM_RIGHT);
        hblimpar.getChildren().add(limpar);
        grid.add(hblimpar, 2, 8);

        limpar.setOnAction(e -> {
            loadQuery10();
            screen.setScene(this.query10);
        });

                    
        Button voltar = new Button("Voltar");
        HBox hbVoltar = new HBox(10);
        hbVoltar.setAlignment(Pos.BOTTOM_LEFT);
        hbVoltar.getChildren().add(voltar);
        grid.add(hbVoltar, 8, 13);

        voltar.setOnAction(e -> {
            loadQueries();
            screen.setScene(this.queries);
        });

        this.query10 = new Scene(grid, 800, 600);
    }    
    
    
    private void loadQuery9() {
        GridPane grid = new GridPane();
        grid.setAlignment(Pos.TOP_CENTER);
        grid.setHgap(20);
        grid.setVgap(20);
        grid.setPadding(new Insets(25, 25, 25, 25));
        
        Label query = new Label("Query 9");
        grid.add(query, 0, 2);
        query.setTextFill(Color.web("#0076a3"));
        query.setFont(new Font(28));
        query.setMaxWidth(Double.MAX_VALUE);
        query.setAlignment(Pos.TOP_LEFT);
        
        Label nome = new Label("Insira o nº de perguntas:");
        grid.add(nome, 0, 5);

        TextField nomeField = new TextField();
        grid.add(nomeField, 1, 5);
        
        Label id1 = new Label("Insira um ID utilizador:");
        grid.add(id1, 0, 6);

        TextField id1field = new TextField();
        grid.add(id1field, 1, 6);
        
        Label id2 = new Label("Insira um ID utilizador:");
        grid.add(id2, 0, 7);

        TextField id2field = new TextField();
        grid.add(id2field, 1, 7);
        
        Button resultado = new Button("Obter resultado");
        HBox hbresultado = new HBox(10);
        hbresultado.setAlignment(Pos.BOTTOM_RIGHT);
        hbresultado.getChildren().add(resultado);
        grid.add(hbresultado, 1, 9);
        
        resultado.setOnAction(e -> {
            int n = Integer.parseInt(nomeField.getText());
            long id_1 = Long.parseLong(id1field.getText());
            long id_2 = Long.parseLong(id2field.getText());
            before = System.currentTimeMillis();
            try {
                List<Long> q9 = qe.bothParticipated(n, id_1, id_2);
                
                Text title = new Text("Últimas " + n + " perguntas em que participaram os dois utilizadores: ");
                title.wrappingWidthProperty().set(215);
                title.setFont(Font.font("Verdana", FontWeight.BOLD, 13));
                title.setTextAlignment(TextAlignment.JUSTIFY);
                grid.add(title, 1, 11);  
                
                Text titleR1 = new Text(q9.toString());
                titleR1.wrappingWidthProperty().set(200);                
                titleR1.setTextAlignment(TextAlignment.JUSTIFY);
                grid.add(titleR1, 1, 12);     
                
            } catch (Exception error) {
            }
            
            after = System.currentTimeMillis();
            
            Label qT = new Label("Takes: " + (after-before) + " ms");
            grid.add(qT, 1, 13);  
        });
        
        
        Button limpar = new Button("Limpar");
        HBox hblimpar = new HBox(10);
        hblimpar.setAlignment(Pos.BOTTOM_RIGHT);
        hblimpar.getChildren().add(limpar);
        grid.add(hblimpar, 2, 9);

        limpar.setOnAction(e -> {
            loadQuery9();
            screen.setScene(this.query9);
        });

                    
        Button voltar = new Button("Voltar");
        HBox hbVoltar = new HBox(10);
        hbVoltar.setAlignment(Pos.BOTTOM_LEFT);
        hbVoltar.getChildren().add(voltar);
        grid.add(hbVoltar, 8, 13);

        voltar.setOnAction(e -> {
            loadQueries();
            screen.setScene(this.queries);
        });

        this.query9 = new Scene(grid, 800, 600);
    }  
    
    private void loadQuery8() {
        GridPane grid = new GridPane();
        grid.setAlignment(Pos.TOP_CENTER);
        grid.setHgap(20);
        grid.setVgap(20);
        grid.setPadding(new Insets(25, 25, 25, 25));

        Label query = new Label("Query 8");
        grid.add(query, 0, 2);
        query.setTextFill(Color.web("#0076a3"));
        query.setFont(new Font(28));
        query.setMaxWidth(Double.MAX_VALUE);
        query.setAlignment(Pos.TOP_LEFT);
        
        Label nome = new Label("Insira um número:");
        grid.add(nome, 0, 5);

        TextField nomeField = new TextField();
        grid.add(nomeField, 1, 5);
        
        Label nome2 = new Label("Insira uma palavra:");
        grid.add(nome2, 0, 6);

        TextField nome2Field = new TextField();
        grid.add(nome2Field, 1, 6);
        
        Button resultado = new Button("Obter resultado");
        HBox hbresultado = new HBox(10);
        hbresultado.setAlignment(Pos.BOTTOM_RIGHT);
        hbresultado.getChildren().add(resultado);
        grid.add(hbresultado, 1, 8);
        
        resultado.setOnAction(e -> {
            int n = Integer.parseInt(nomeField.getText());
            String pal = nome2Field.getText();
            before = System.currentTimeMillis();
            try {
                List<Long> q8 = qe.containsWord(n, pal);
                
                Text title = new Text(n + "perguntas com a palavra " + pal +  " no título: ");
                title.wrappingWidthProperty().set(215);
                title.setFont(Font.font("Verdana", FontWeight.BOLD, 13));
                title.setTextAlignment(TextAlignment.JUSTIFY);
                grid.add(title, 1, 11);  
                
                Text titleR1 = new Text(q8.toString());
                titleR1.wrappingWidthProperty().set(200);                
                titleR1.setTextAlignment(TextAlignment.JUSTIFY);
                grid.add(titleR1, 1, 12);     
                
            } catch (Exception error) {
            }
            
            after = System.currentTimeMillis();
            
            Label qT = new Label("Takes: " + (after-before) + " ms");
            grid.add(qT, 1, 13);  
        });
        
        
        Button limpar = new Button("Limpar");
        HBox hblimpar = new HBox(10);
        hblimpar.setAlignment(Pos.BOTTOM_RIGHT);
        hblimpar.getChildren().add(limpar);
        grid.add(hblimpar, 2, 8);

        limpar.setOnAction(e -> {
            loadQuery8();
            screen.setScene(this.query8);
        });

                    
        Button voltar = new Button("Voltar");
        HBox hbVoltar = new HBox(10);
        hbVoltar.setAlignment(Pos.BOTTOM_LEFT);
        hbVoltar.getChildren().add(voltar);
        grid.add(hbVoltar, 8, 13);

        voltar.setOnAction(e -> {
            loadQueries();
            screen.setScene(this.queries);
        });

        this.query8 = new Scene(grid, 800, 600);
    }    
    
    private void loadQuery7() {
        GridPane grid = new GridPane();
        grid.setAlignment(Pos.TOP_CENTER);
        grid.setHgap(20);
        grid.setVgap(20);
        grid.setPadding(new Insets(25, 25, 25, 25));

        Label query = new Label("Query 7");
        grid.add(query, 1, 2);
        query.setTextFill(Color.web("#0076a3"));
        query.setFont(new Font(28));
        query.setMaxWidth(Double.MAX_VALUE);
        query.setAlignment(Pos.TOP_LEFT);
        
        Label nome = new Label("Insira um número:");
        grid.add(nome, 1, 5);

        TextField nomeField = new TextField();
        grid.add(nomeField, 2, 5);
        
        final DatePicker dataField1 = new DatePicker();
        dataField1.setPromptText("Data inicial");
        grid.add(dataField1, 1, 7);

        final DatePicker dataField2 = new DatePicker();
        dataField2.setPromptText("Data final");
        grid.add(dataField2, 2, 7);
                
        Button resultado = new Button("Obter resultado");
        HBox hbresultado = new HBox(10);
        hbresultado.setAlignment(Pos.BOTTOM_RIGHT);
        hbresultado.getChildren().add(resultado);
        grid.add(hbresultado, 2, 8);
        
        resultado.setOnAction(e -> {
            before = System.currentTimeMillis();
            int n = Integer.parseInt(nomeField.getText());
            
            try {
                List<Long> q7 = qe.mostAnsweredQuestions(n, 
                          LocalDate.parse(dataField1.getValue().toString()),
                          LocalDate.parse(dataField2.getValue().toString())); 
                    
                    
                TextFlow flowqr1 = new TextFlow();
                Text title = new Text("IDs das " + n + " perguntas com mais respostas: ");
                title.setFont(Font.font("Verdana", FontWeight.BOLD, 13));
                title.setTextAlignment(TextAlignment.JUSTIFY);
                Text titleR1 = new Text(q7.toString());
                titleR1.setTextAlignment(TextAlignment.JUSTIFY);
                flowqr1.getChildren().addAll(title, titleR1);
                flowqr1.setMaxHeight(2000);
                flowqr1.setMaxWidth(190);
                grid.add(flowqr1, 1, 11);                
            }
              catch (Exception error) {
            }
            
            after = System.currentTimeMillis();
            
            Label q1T = new Label("Takes: " + (after-before) + " ms");
            grid.add(q1T, 1, 13);  
        });
        
        
        Button limpar = new Button("Limpar");
        HBox hblimpar = new HBox(10);
        hblimpar.setAlignment(Pos.BOTTOM_RIGHT);
        hblimpar.getChildren().add(limpar);
        grid.add(hblimpar, 3, 8);

        limpar.setOnAction(e -> {
            loadQuery7();
            screen.setScene(this.query7);
        });

                    
        Button voltar = new Button("Voltar");
        HBox hbVoltar = new HBox(10);
        hbVoltar.setAlignment(Pos.BOTTOM_LEFT);
        hbVoltar.getChildren().add(voltar);
        grid.add(hbVoltar, 8, 13);

        voltar.setOnAction(e -> {
            loadQueries();
            screen.setScene(this.queries);
        });

        this.query7 = new Scene(grid, 800, 600);
    }
    
    private void loadQuery6() {
        GridPane grid = new GridPane();
        grid.setAlignment(Pos.TOP_CENTER);
        grid.setHgap(20);
        grid.setVgap(20);
        grid.setPadding(new Insets(25, 25, 25, 25));

        Label query = new Label("Query 6");
        grid.add(query, 1, 2);
        query.setTextFill(Color.web("#0076a3"));
        query.setFont(new Font(28));
        query.setMaxWidth(Double.MAX_VALUE);
        query.setAlignment(Pos.TOP_LEFT);      
        
        Label nome = new Label("Insira um número:");
        grid.add(nome, 1, 5);

        TextField nomeField = new TextField();
        grid.add(nomeField, 2, 5);
        
        final DatePicker dataField1 = new DatePicker();
        dataField1.setPromptText("Data inicial");
        grid.add(dataField1, 1, 7);

        final DatePicker dataField2 = new DatePicker();
        dataField2.setPromptText("Data final");
        grid.add(dataField2, 2, 7);
                
        Button resultado = new Button("Obter resultado");
        HBox hbresultado = new HBox(10);
        hbresultado.setAlignment(Pos.BOTTOM_RIGHT);
        hbresultado.getChildren().add(resultado);
        grid.add(hbresultado, 2, 8);
        
        resultado.setOnAction(e -> {
            before = System.currentTimeMillis();
            
            List<Long> q6 = new ArrayList<>();
            int n = Integer.parseInt(nomeField.getText());
            try {
                q6 = qe.mostVotedAnswers(n, 
                          LocalDate.parse(dataField1.getValue().toString()),
                          LocalDate.parse(dataField2.getValue().toString())); 
                    
                    
                TextFlow flowqr1 = new TextFlow();
                Text title = new Text("IDs das " + n + " respostas com mais votos: ");
                title.setFont(Font.font("Verdana", FontWeight.BOLD, 13));
                title.setTextAlignment(TextAlignment.JUSTIFY);
                Text titleR1 = new Text(q6.toString());
                titleR1.setTextAlignment(TextAlignment.JUSTIFY);
                flowqr1.getChildren().addAll(title, titleR1);
                flowqr1.setMaxHeight(2000);
                flowqr1.setMaxWidth(190);
                grid.add(flowqr1, 1, 11);                
            } catch (IndexOutOfBoundsException a) {
                Text q1T = new Text("Não existem " + n + " respostas.");
                q1T.wrappingWidthProperty().set(190);
                grid.add(q1T, 1, 12); 
            } 
              catch (Exception error) {
            }
            
            after = System.currentTimeMillis();
            
            Label q1T = new Label("Takes: " + (after-before) + " ms");
            grid.add(q1T, 1, 13);  
        });
        
        
        Button limpar = new Button("Limpar");
        HBox hblimpar = new HBox(10);
        hblimpar.setAlignment(Pos.BOTTOM_RIGHT);
        hblimpar.getChildren().add(limpar);
        grid.add(hblimpar, 3, 8);

        limpar.setOnAction(e -> {
            loadQuery6();
            screen.setScene(this.query6);
        });

                    
        Button voltar = new Button("Voltar");
        HBox hbVoltar = new HBox(10);
        hbVoltar.setAlignment(Pos.BOTTOM_LEFT);
        hbVoltar.getChildren().add(voltar);
        grid.add(hbVoltar, 8, 13);

        voltar.setOnAction(e -> {
            loadQueries();
            screen.setScene(this.queries);
        });

        this.query6 = new Scene(grid, 800, 600);
    }
    
    private void loadQuery5() {
        GridPane grid = new GridPane();
        grid.setAlignment(Pos.TOP_CENTER);
        grid.setHgap(20);
        grid.setVgap(20);
        grid.setPadding(new Insets(25, 25, 25, 25));

        Label query = new Label("Query 5");
        grid.add(query, 0, 2);
        query.setTextFill(Color.web("#0076a3"));
        query.setFont(new Font(28));
        query.setMaxWidth(Double.MAX_VALUE);
        query.setAlignment(Pos.TOP_LEFT);
        
        Label nome = new Label("Insira um nº de utilizador:");
        grid.add(nome, 0, 5);

        TextField nomeField = new TextField();
        grid.add(nomeField, 1, 5);
        
        Button resultado = new Button("Obter resultado");
        HBox hbresultado = new HBox(10);
        hbresultado.setAlignment(Pos.BOTTOM_RIGHT);
        hbresultado.getChildren().add(resultado);
        grid.add(hbresultado, 1, 8);
        
        resultado.setOnAction(e -> {
            long n = Long.parseLong(nomeField.getText());
            before = System.currentTimeMillis();
            try {
                Pair<String, List<Long>> q5 = qe.getUserInfo(n);
                
                TextFlow flowqr1 = new TextFlow();
                Text title = new Text("Short Bio : ");
                title.setFont(Font.font("Verdana", FontWeight.BOLD, 13));
                title.setTextAlignment(TextAlignment.JUSTIFY);
                Text titleR1 = new Text(q5.getFst());
                titleR1.setTextAlignment(TextAlignment.JUSTIFY);
                flowqr1.getChildren().addAll(title, titleR1);
                flowqr1.setMaxHeight(2000);
                flowqr1.setMaxWidth(310);
                grid.add(flowqr1, 1, 9);                
                                
                TextFlow flowqr2 = new TextFlow();
                Text title2 = new Text("IDs últimos 10 posts: ");
                title2.setFont(Font.font("Verdana", FontWeight.BOLD, 13));
                title2.setTextAlignment(TextAlignment.JUSTIFY);
                Text titleR2 = new Text(q5.getSnd().toString());
                titleR2.setTextAlignment(TextAlignment.JUSTIFY);
                flowqr2.getChildren().addAll(title2, titleR2);
                flowqr2.setMaxHeight(2000);
                flowqr2.setMaxWidth(310);
                grid.add(flowqr2, 1, 10);   
                
            } catch (Exception error) {
            }
            
            after = System.currentTimeMillis();
            
            Label qT = new Label("Takes: " + (after-before) + " ms");
            grid.add(qT, 1, 11);  
        });
        
        
        Button limpar = new Button("Limpar");
        HBox hblimpar = new HBox(10);
        hblimpar.setAlignment(Pos.BOTTOM_RIGHT);
        hblimpar.getChildren().add(limpar);
        grid.add(hblimpar, 2, 8);

        limpar.setOnAction(e -> {
            loadQuery5();
            screen.setScene(this.query5);
        });

                    
        Button voltar = new Button("Voltar");
        HBox hbVoltar = new HBox(10);
        hbVoltar.setAlignment(Pos.BOTTOM_LEFT);
        hbVoltar.getChildren().add(voltar);
        grid.add(hbVoltar, 8, 13);

        voltar.setOnAction(e -> {
            loadQueries();
            screen.setScene(this.queries);
        });

        this.query5 = new Scene(grid, 800, 600);
    }
    
    private void loadQuery4() {
        GridPane grid = new GridPane();
        grid.setAlignment(Pos.TOP_CENTER);
        grid.setHgap(20);
        grid.setVgap(20);
        grid.setPadding(new Insets(25, 25, 25, 25));

        Label query = new Label("Query 4");
        grid.add(query, 1, 2);
        query.setTextFill(Color.web("#0076a3"));
        query.setFont(new Font(28));
        query.setMaxWidth(Double.MAX_VALUE);
        query.setAlignment(Pos.TOP_LEFT);
        
        Label nome = new Label("Insira uma tag:");
        grid.add(nome, 1, 5);

        TextField nomeField = new TextField();
        grid.add(nomeField, 2, 5);
        
        final DatePicker dataField1 = new DatePicker();
        dataField1.setPromptText("Data inicial");
        grid.add(dataField1, 1, 7);

        final DatePicker dataField2 = new DatePicker();
        dataField2.setPromptText("Data final");
        grid.add(dataField2, 2, 7);
                
        Button resultado = new Button("Obter resultado");
        HBox hbresultado = new HBox(10);
        hbresultado.setAlignment(Pos.BOTTOM_RIGHT);
        hbresultado.getChildren().add(resultado);
        grid.add(hbresultado, 2, 8);
        
        resultado.setOnAction(e -> {
            before = System.currentTimeMillis();
            
            try {                
                List<Long> q4 = qe.questionsWithTag(nomeField.getText(), 
                    LocalDate.parse(dataField1.getValue().toString()),
                    LocalDate.parse(dataField2.getValue().toString()));    
                    
                TextFlow flowqr1 = new TextFlow();
                Text title = new Text("IDs das perguntas: ");
                title.setFont(Font.font("Verdana", FontWeight.BOLD, 13));
                title.setTextAlignment(TextAlignment.JUSTIFY);
                Text titleR1 = new Text(q4.toString());
                titleR1.setTextAlignment(TextAlignment.JUSTIFY);
                flowqr1.getChildren().addAll(title, titleR1);
                flowqr1.setMaxHeight(2000);
                flowqr1.setMaxWidth(190);
                grid.add(flowqr1, 1, 11);                
            }
              catch (Exception error) {
            }
            
            after = System.currentTimeMillis();
            
            Label q1T = new Label("Takes: " + (after-before) + " ms");
            grid.add(q1T, 1, 13);  
        });
        
        
        Button limpar = new Button("Limpar");
        HBox hblimpar = new HBox(10);
        hblimpar.setAlignment(Pos.BOTTOM_RIGHT);
        hblimpar.getChildren().add(limpar);
        grid.add(hblimpar, 3, 8);

        limpar.setOnAction(e -> {
            loadQuery4();
            screen.setScene(this.query4);
        });

                    
        Button voltar = new Button("Voltar");
        HBox hbVoltar = new HBox(10);
        hbVoltar.setAlignment(Pos.BOTTOM_LEFT);
        hbVoltar.getChildren().add(voltar);
        grid.add(hbVoltar, 8, 13);

        voltar.setOnAction(e -> {
            loadQueries();
            screen.setScene(this.queries);
        });

        this.query4 = new Scene(grid, 800, 600);
    }
    
    private void loadQuery3() {
        GridPane grid = new GridPane();
        grid.setAlignment(Pos.TOP_CENTER);
        grid.setHgap(20);
        grid.setVgap(20);
        grid.setPadding(new Insets(25, 25, 25, 25));
        
        Label query = new Label("Query 3");
        grid.add(query, 1, 2);
        query.setTextFill(Color.web("#0076a3"));
        query.setFont(new Font(28));
        query.setMaxWidth(Double.MAX_VALUE);
        query.setAlignment(Pos.TOP_LEFT);
        
        final DatePicker dataField1 = new DatePicker();
        dataField1.setPromptText("Data inicial");
        grid.add(dataField1, 1, 7);

        final DatePicker dataField2 = new DatePicker();
        dataField2.setPromptText("Data final");
        grid.add(dataField2, 2, 7);
                
        Button resultado = new Button("Obter resultado");
        HBox hbresultado = new HBox(10);
        hbresultado.setAlignment(Pos.BOTTOM_RIGHT);
        hbresultado.getChildren().add(resultado);
        grid.add(hbresultado, 2, 8);
        
        resultado.setOnAction(e -> {
            before = System.currentTimeMillis();
            
            try {                
                Pair<Long,Long> q3 = qe.totalPosts(LocalDate.parse(dataField1.getValue().toString()),
                    LocalDate.parse(dataField2.getValue().toString()));
                    
                TextFlow flowqr1 = new TextFlow();
                Text title = new Text("Nº de perguntas: ");
                title.setFont(Font.font("Verdana", FontWeight.BOLD, 13));
                title.setTextAlignment(TextAlignment.JUSTIFY);
                Text titleR1 = new Text(Long.toString(q3.getFst()));
                titleR1.setTextAlignment(TextAlignment.JUSTIFY);
                flowqr1.getChildren().addAll(title, titleR1);
                flowqr1.setMaxHeight(2000);
                flowqr1.setMaxWidth(190);
                grid.add(flowqr1, 1, 11);                
                                
                TextFlow flowqr2 = new TextFlow();
                Text title2 = new Text("Nº de respostas: ");
                title2.setFont(Font.font("Verdana", FontWeight.BOLD, 13));
                title2.setTextAlignment(TextAlignment.JUSTIFY);
                Text titleR2 = new Text(Long.toString(q3.getSnd()));
                titleR2.setTextAlignment(TextAlignment.JUSTIFY);
                flowqr2.getChildren().addAll(title2, titleR2);
                flowqr2.setMaxHeight(2000);
                flowqr2.setMaxWidth(190);
                grid.add(flowqr2, 1, 12); 
                
            }
              catch (Exception error) {
            }
            
            after = System.currentTimeMillis();
            
            Label q1T = new Label("Takes: " + (after-before) + " ms");
            grid.add(q1T, 1, 13);  
        });
        
        
        Button limpar = new Button("Limpar");
        HBox hblimpar = new HBox(10);
        hblimpar.setAlignment(Pos.BOTTOM_RIGHT);
        hblimpar.getChildren().add(limpar);
        grid.add(hblimpar, 3, 8);

        limpar.setOnAction(e -> {
            loadQuery3();
            screen.setScene(this.query3);
        });

                    
        Button voltar = new Button("Voltar");
        HBox hbVoltar = new HBox(10);
        hbVoltar.setAlignment(Pos.BOTTOM_LEFT);
        hbVoltar.getChildren().add(voltar);
        grid.add(hbVoltar, 8, 13);

        voltar.setOnAction(e -> {
            loadQueries();
            screen.setScene(this.queries);
        });

        this.query3 = new Scene(grid, 800, 600);
    }
    
    private void loadQuery2() {
        GridPane grid = new GridPane();
        grid.setAlignment(Pos.TOP_CENTER);
        grid.setHgap(20);
        grid.setVgap(20);
        grid.setPadding(new Insets(25, 25, 25, 25));
        
        Label query = new Label("Query 2");
        grid.add(query, 0, 2);
        query.setTextFill(Color.web("#0076a3"));
        query.setFont(new Font(28));
        query.setMaxWidth(Double.MAX_VALUE);
        query.setAlignment(Pos.TOP_LEFT);
        
        Label nome = new Label("Insira um número:");
        grid.add(nome, 0, 5);

        TextField nomeField = new TextField();
        grid.add(nomeField, 1, 5);
        
        Button resultado = new Button("Obter resultado");
        HBox hbresultado = new HBox(10);
        hbresultado.setAlignment(Pos.BOTTOM_RIGHT);
        hbresultado.getChildren().add(resultado);
        grid.add(hbresultado, 1, 8);
        
        resultado.setOnAction(e -> {
            int n = Integer.parseInt(nomeField.getText());
            before = System.currentTimeMillis();
            try {
                List<Long> q2 = qe.topMostActive(n);
                
                Text title = new Text("Top " + n + " melhores utilizadores: ");
                title.wrappingWidthProperty().set(215);
                title.setFont(Font.font("Verdana", FontWeight.BOLD, 13));
                title.setTextAlignment(TextAlignment.JUSTIFY);
                grid.add(title, 1, 11);  
                
                Text titleR1 = new Text(q2.toString());
                titleR1.wrappingWidthProperty().set(200);                
                titleR1.setTextAlignment(TextAlignment.JUSTIFY);
                grid.add(titleR1, 1, 12);     
                
            } catch (Exception error) {
            }
            
            after = System.currentTimeMillis();
            
            Label qT = new Label("Takes: " + (after-before) + " ms");
            grid.add(qT, 1, 13);  
        });
        
        
        Button limpar = new Button("Limpar");
        HBox hblimpar = new HBox(10);
        hblimpar.setAlignment(Pos.BOTTOM_RIGHT);
        hblimpar.getChildren().add(limpar);
        grid.add(hblimpar, 2, 8);

        limpar.setOnAction(e -> {
            loadQuery2();
            screen.setScene(this.query2);
        });

                    
        Button voltar = new Button("Voltar");
        HBox hbVoltar = new HBox(10);
        hbVoltar.setAlignment(Pos.BOTTOM_LEFT);
        hbVoltar.getChildren().add(voltar);
        grid.add(hbVoltar, 8, 13);

        voltar.setOnAction(e -> {
            loadQueries();
            screen.setScene(this.queries);
        });

        this.query2 = new Scene(grid, 800, 600);
    }
        
    
    private void loadQuery1() {
        GridPane grid = new GridPane();
        grid.setAlignment(Pos.TOP_CENTER);
        grid.setHgap(20);
        grid.setVgap(20);
        grid.setPadding(new Insets(25, 25, 25, 25));
        
        Label query = new Label("Query 1");
        grid.add(query, 0, 2);
        query.setTextFill(Color.web("#0076a3"));
        query.setFont(new Font(28));
        query.setMaxWidth(Double.MAX_VALUE);
        query.setAlignment(Pos.TOP_LEFT);
        
        Label nome = new Label("Insere o ID do post: ");
        grid.add(nome, 0, 5);

        TextField nomeField = new TextField();
        grid.add(nomeField, 1, 5);
        
        Button resultado = new Button("Obter resultado");
        HBox hbresultado = new HBox(10);
        hbresultado.setAlignment(Pos.BOTTOM_RIGHT);
        hbresultado.getChildren().add(resultado);
        grid.add(hbresultado, 1, 8);
        
        resultado.setOnAction(e -> {
            long id_post = Long.parseLong(nomeField.getText());
            before = System.currentTimeMillis();
            Pair<String,String> q1 = new Pair("null", "null");
            try {
                q1 = qe.infoFromPost(id_post);
                
                TextFlow flowqr1 = new TextFlow();
                Text title = new Text("Title: ");
                title.setFont(Font.font("Verdana", FontWeight.BOLD, 13));
                title.setTextAlignment(TextAlignment.JUSTIFY);
                Text titleR1 = new Text(q1.getFst());
                titleR1.setTextAlignment(TextAlignment.JUSTIFY);
                flowqr1.getChildren().addAll(title, titleR1);
                flowqr1.setMaxHeight(2000);
                flowqr1.setMaxWidth(190);
                grid.add(flowqr1, 1, 11);                
                                
                TextFlow flowqr2 = new TextFlow();
                Text title2 = new Text("Username: ");
                title2.setFont(Font.font("Verdana", FontWeight.BOLD, 13));
                title2.setTextAlignment(TextAlignment.JUSTIFY);
                Text titleR2 = new Text(q1.getSnd());
                titleR2.setTextAlignment(TextAlignment.JUSTIFY);
                flowqr2.getChildren().addAll(title2, titleR2);
                flowqr2.setMaxHeight(2000);
                flowqr2.setMaxWidth(190);
                grid.add(flowqr2, 1, 12); 
                
            } catch (NoPostIdException a) {
                Text q1T = new Text(id_post + " não identifica um post.");
                q1T.wrappingWidthProperty().set(190);
                grid.add(q1T, 1, 12); 
            }
              catch (Exception error) {
            }
            
            after = System.currentTimeMillis();
            
            Label q1T = new Label("Takes: " + (after-before) + " ms");
            grid.add(q1T, 1, 13);  
        });
        
        
        Button limpar = new Button("Limpar");
        HBox hblimpar = new HBox(10);
        hblimpar.setAlignment(Pos.BOTTOM_RIGHT);
        hblimpar.getChildren().add(limpar);
        grid.add(hblimpar, 2, 8);

        limpar.setOnAction(e -> {
            loadQuery1();
            screen.setScene(this.query1);
        });

                    
        Button voltar = new Button("Voltar");
        HBox hbVoltar = new HBox(10);
        hbVoltar.setAlignment(Pos.BOTTOM_LEFT);
        hbVoltar.getChildren().add(voltar);
        grid.add(hbVoltar, 8, 13);

        voltar.setOnAction(e -> {
            loadQueries();
            screen.setScene(this.queries);
        });

        this.query1 = new Scene(grid, 800, 600);
    }
    
    
    private void loadQueries() {
        GridPane grid = new GridPane();
        grid.setAlignment(Pos.TOP_LEFT);
        grid.setHgap(8);
        grid.setVgap(8);
        grid.setPadding(new Insets(25, 25, 25, 25));

        Label nome = new Label("Olá, " + this.nome_utilizador + "!");
        grid.add(nome, 0, 0);
        nome.setFont(new Font(28));
        nome.setMaxWidth(Double.MAX_VALUE);
        nome.setAlignment(Pos.CENTER);
        
        Button query1 = new Button("Query 1");
        HBox hbquery1 = new HBox(10);
        hbquery1.setAlignment(Pos.CENTER);
        hbquery1.getChildren().add(query1);
        grid.add(hbquery1, 1, 15);

        query1.setOnAction(e -> {
            loadQuery1();
            screen.setScene(this.query1);
        });
        
        Button query2 = new Button("Query 2");
        HBox hbquery2 = new HBox(10);
        hbquery2.setAlignment(Pos.CENTER);
        hbquery2.getChildren().add(query2);
        grid.add(hbquery2, 2, 15);

        query2.setOnAction(e -> {
            loadQuery2();
            screen.setScene(this.query2);
        });
        
        Button query3 = new Button("Query 3");
        HBox hbquery3 = new HBox(10);
        hbquery3.setAlignment(Pos.CENTER);
        hbquery3.getChildren().add(query3);
        grid.add(hbquery3, 3, 15);

        query3.setOnAction(e -> {
            loadQuery3();
            screen.setScene(this.query3);
        });

        Button query4 = new Button("Query 4");
        HBox hbquery4 = new HBox(10);
        hbquery4.setAlignment(Pos.CENTER);
        hbquery4.getChildren().add(query4);
        grid.add(hbquery4, 4, 15);

        query4.setOnAction(e -> {
            loadQuery4();
            screen.setScene(this.query4);
        });

        Button query5 = new Button("Query 5");
        HBox hbquery5 = new HBox(10);
        hbquery5.setAlignment(Pos.CENTER);
        hbquery5.getChildren().add(query5);
        grid.add(hbquery5, 5, 15);

        query5.setOnAction(e -> {
            loadQuery5();
            screen.setScene(this.query5);
        });
        
        Button query6 = new Button("Query 6");
        HBox hbquery6 = new HBox(10);
        hbquery6.setAlignment(Pos.CENTER);
        hbquery6.getChildren().add(query6);
        grid.add(hbquery6, 1, 30);

        query6.setOnAction(e -> {
            loadQuery6();
            screen.setScene(this.query6);
        });

        Button query7 = new Button("Query 7");
        HBox hbquery7 = new HBox(10);
        hbquery7.setAlignment(Pos.CENTER);
        hbquery7.getChildren().add(query7);
        grid.add(hbquery7, 2, 30);

        query7.setOnAction(e -> {
            loadQuery7();
            screen.setScene(this.query7);
        });        
        
        Button query8 = new Button("Query 8");
        HBox hbquery8 = new HBox(10);
        hbquery8.setAlignment(Pos.CENTER);
        hbquery8.getChildren().add(query8);
        grid.add(hbquery8, 3, 30);

        query8.setOnAction(e -> {
            loadQuery8();
            screen.setScene(this.query8);
        });

        Button query9 = new Button("Query 9");
        HBox hbquery9 = new HBox(10);
        hbquery9.setAlignment(Pos.CENTER);
        hbquery9.getChildren().add(query9);
        grid.add(hbquery9, 4, 30);

        query9.setOnAction(e -> {
            loadQuery9();
            screen.setScene(this.query9);
        });            

        Button query10 = new Button("Query 10");
        HBox hbquery10 = new HBox(10);
        hbquery10.setAlignment(Pos.CENTER);
        hbquery10.getChildren().add(query10);
        grid.add(hbquery10, 5, 30);

        query10.setOnAction(e -> {
            loadQuery10();
            screen.setScene(this.query10);
        });

        Button query11 = new Button("Query 11");
        HBox hbquery11 = new HBox(10);
        hbquery11.setAlignment(Pos.CENTER);
        hbquery11.getChildren().add(query11);
        grid.add(hbquery11, 6, 30);

        query11.setOnAction(e -> {
            loadQuery11();
            screen.setScene(this.query11);
        });    
        
        Label loadtime = new Label(time_load + " ms");
        loadtime.setAlignment(Pos.TOP_RIGHT);
        grid.add(loadtime, 0, 45);        
        
        
        Button voltar = new Button("Voltar");
        HBox hbVoltar = new HBox(10);
        hbVoltar.setAlignment(Pos.BOTTOM_RIGHT);
        hbVoltar.getChildren().add(voltar);
        grid.add(hbVoltar, 6, 45);

        voltar.setOnAction(e -> {
            loadMain();
            screen.setScene(this.main);
        });

        this.queries = new Scene(grid, 800, 600);
    }
    
    
    private void loadMain() {
        GridPane grid = new GridPane();
        grid.setAlignment(Pos.CENTER);
        grid.setHgap(20);
        grid.setVgap(20);
        grid.setPadding(new Insets(25, 25, 25, 25));
<<<<<<< HEAD

=======
        
>>>>>>> cbf6d32b5392f7fb5546343d3c1fd3e39cd57db3
        Image img = new Image("imgs/logo.png");
        ImageView imgView = new ImageView(img);
        imgView.setFitWidth(300);
        imgView.setFitHeight(250);
        grid.add(imgView, 1, 0);

        Label nome = new Label("Nome:");
        grid.add(nome, 0, 2);

        TextField nomeField = new TextField();
        grid.add(nomeField, 1, 2);
        
<<<<<<< HEAD
=======
        Label path = new Label("Path Completo:");
        grid.add(path, 0, 3);

        TextField pathField = new TextField();
        grid.add(pathField, 1, 3);     
          
           
>>>>>>> cbf6d32b5392f7fb5546343d3c1fd3e39cd57db3
        Button login = new Button("Entrar");
        HBox hbLogin = new HBox(10);
        hbLogin.setAlignment(Pos.CENTER);
        hbLogin.getChildren().add(login);
<<<<<<< HEAD
        grid.add(hbLogin, 1, 4);
=======
        grid.add(hbLogin, 1, 5);
>>>>>>> cbf6d32b5392f7fb5546343d3c1fd3e39cd57db3

        login.setOnAction(e -> {
            String nome_utilizador = nomeField.getText();
            this.nome_utilizador = nome_utilizador;
<<<<<<< HEAD
            loadQueries();
            screen.setScene(this.queries);
        });

=======
                    this.qe = new TCD_Community();

            boolean loadComplete = false;
            
            try {
                long before_load = System.currentTimeMillis();
                qe.load(pathField.getText());
                long after_load = System.currentTimeMillis();
                time_load = after_load - before_load;
                loadComplete = true;
            }
            catch (IndexOutOfBoundsException a) {
                System.out.println("Error: " + a.getMessage());
            }
            catch (SAXException a) {
                System.out.println("SAXException: " + a.getMessage());
            }
            catch (ParserConfigurationException a) {
                System.out.println("ParserConfigurationException: " + a.getMessage());
            }
            catch (IOException a) {
                System.out.println("IOException: " + a.getMessage());
            }
        
            //verifica se o load foi completado com sucesso
            if(!loadComplete) {
                return;
            }     
            
            
            loadQueries();
            screen.setScene(this.queries);
        });
        
>>>>>>> cbf6d32b5392f7fb5546343d3c1fd3e39cd57db3
        Button sair = new Button("Sair");
        HBox hbSair = new HBox(10);
        hbSair.setAlignment(Pos.CENTER);
        hbSair.getChildren().add(sair);
        grid.add(hbSair, 1, 6);

        sair.setOnAction(e -> {
            Platform.exit();
        });


        this.main = new Scene(grid, 800, 600);
    }

    /**
     * Ponto de entrada principal para a aplicação
     *
     * @param primaryStage estado inicial da aplicação
     */
    public void start(Stage primaryStage) {
        this.screen = primaryStage;
        this.screen.setTitle("Stack Overflow Information Processing");
        this.screen.setWidth(800);
        this.screen.setHeight(600);

<<<<<<< HEAD
        this.qe = new TCD_Community();

        boolean loadComplete = false;
        
        final Parameters params = getParameters();
        final List<String> parameters = params.getRaw();
System.out.println(parameters.toString());

        
        
        try {
            long before_load = System.currentTimeMillis();
            qe.load("/Users/cam/Desktop/Grupo1/proj-java/dump/ubuntu");
            long after_load = System.currentTimeMillis();
            time_load = after_load - before_load;
            loadComplete = true;
        }
        catch (IndexOutOfBoundsException e) {
            System.out.println("Error: " + e.getMessage());
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
        
        //verifica se o load foi completado com sucesso
        if(!loadComplete) {
            return;
        }

=======
>>>>>>> cbf6d32b5392f7fb5546343d3c1fd3e39cd57db3
        this.loadMain();

        this.screen.setScene(this.main);
        this.screen.show();
    }

    public static void main(final String[] args) {
        launch(args);
    }
}
