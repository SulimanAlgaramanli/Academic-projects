
var mistakes = 0;
var num_words = 0;
var len = 0;
var start = new Date().getTime();
var end = 0.0;
var time = 0.0;
var WPM = 0.0;
var acc = 0.0;
//var t=0;
var win_flag=0;

function accWpm() 
{
  time = (end - start) ;
  var mm = Math.floor((time % (1000 * 60 * 60)) / (1000 * 60));
  var ss = Math.floor((time % (1000 * 60)) / 1000);
  a = "Time : ";
  mm ;
  b = ":";
  ss; //الوقت المستغرق
  var minute=mm+(ss/60); //الزمن المستغرق بالدقائق
  // alert("Time Rate :" +minute);
  c = "\n Number Of Words : ";
  num_words;
  WPM = (num_words / (minute));
  d = "\n WPM : " ;
   WPM;//عدد الكلمات في الدقيقة
  e= "\n mistakes : ";
   mistakes;//عدد الاخطاء
  acc = ( 1 - (mistakes/len) ) * 100;
  f="\n Accuarcy : " ;
   //acc ;
   g="%";//نسبة الدقة
   
   R1=a+mm+b+ss;
   R2=c+num_words;
   R3=d+WPM;
   R4=e+mistakes;
   R5=f+acc+g;
   R=R1+R2+R3+R4+R5;
   alert (R);
}

function compar(event)
{
    t_player = document.getElementById("player").value;
    t_game = document.getElementById("text_game").innerHTML;

    for(i=0;t_player[i] != null;i++)
    {
       
        if(t_player[i] == t_game[i] )
        {
          document.getElementById("player").style.backgroundColor  = "rgb(150, 250, 125)" ;   //= "green" ; 
        }
        else
        {
          document.getElementById("player").style.backgroundColor  = "rgb(240, 83, 77)" ;   //= "red" ; 
          if(event.key!="Enter" && event.key!="Backspace" && event.key!="Delete" && event.key!="ArrowLeft" && event.key!="ArrowRight" && event.key!="ArrowDown" && event.key!="ArrowUp")
          {
            mistakes = mistakes+1;
          }
          break;
        } 
    }
   
    if( document.getElementById("player").value == document.getElementById("text_game").innerHTML )
    {
        alert("You Win");
        win_flag=1;
        end_game();
    }
}
function end_game()
{
  end = new Date().getTime();
  len = document.getElementById("player").value.length;
  num_words = len / 5;
  accWpm ();
  // mistakes = Math.sqrt(mistakes); 
  //location.replace('./result.php');
}

//time

var dt = new Date();
dt.setMinutes( dt.getMinutes() + 0 );
 dt.setSeconds( dt.getSeconds() + 20 );
 start = new Date().getTime();
 var distance =0;

// Update the count down every 1 second
var x = setInterval(function() {
  if(win_flag == 0)
  {
    var now = new Date().getTime();
      
    // Find the distance between now and the count down date
    distance = dt - now;
    var minutes = Math.floor((distance % (1000 * 60 * 60)) / (1000 * 60));
    var seconds = Math.floor((distance % (1000 * 60)) / 1000);
      
    // Output the result in an element with id="demo"
    document.getElementById("demo").innerHTML =  minutes + ":" +  seconds ;
      
    // If the count down is over, write some text 
    if (distance < 0) 
    {
      //read only;
      clearInterval(x);
      document.getElementById("demo").innerHTML = "EXPIRED";
      alert("Lose");
      end_game();
      
    }
  }


}, 1000);

