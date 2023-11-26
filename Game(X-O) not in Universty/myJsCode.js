function view_x_o(TOY)
{
    if(document.getElementById(TOY).textContent=="-")
    {
        if(document.getElementById("mahfe").textContent == "1")
        {
            document.getElementById(TOY).innerHTML = "X";
            document.getElementById(TOY).style.backgroundColor = "gold";
            document.getElementById("mahfe").innerHTML = "2";

            document.getElementById("pX").style.backgroundColor = "white";
            document.getElementById("pO").style.backgroundColor = "yellowgreen";


    }
    else 
    {
        document.getElementById(TOY).innerHTML = "O";
        document.getElementById(TOY).style.backgroundColor = "yellowgreen";
        document.getElementById("mahfe").innerHTML = "1";

        document.getElementById("pO").style.backgroundColor = "white";
        document.getElementById("pX").style.backgroundColor = "gold";

    }
  
        result();

    }
   
    
}
function result() {
    r1 = document.getElementById("B1").textContent;
    r2 = document.getElementById("B2").textContent;
    r3 = document.getElementById("B3").textContent;
    r4 = document.getElementById("B4").textContent;
    r5 = document.getElementById("B5").textContent;
    r6 = document.getElementById("B6").textContent;
    r7 = document.getElementById("B7").textContent;
    r8 = document.getElementById("B8").textContent;
    r9 = document.getElementById("B9").textContent;

    if ((r1 != "-" && r1 == r2 && r2 == r3) )
    {
        document.getElementById("B1").style.backgroundColor = "chocolate";
        document.getElementById("B2").style.backgroundColor = "chocolate";
        document.getElementById("B3").style.backgroundColor = "chocolate";
        win();

    }
    else if (r4 != "-" && r4 == r5 && r5 == r6)
    {
        document.getElementById("B4").style.backgroundColor = "chocolate";
        document.getElementById("B5").style.backgroundColor = "chocolate";
        document.getElementById("B6").style.backgroundColor = "chocolate";
        win();
    }
    else if (r7 != "-" && r7 == r8 && r8 == r9) {
        document.getElementById("B7").style.backgroundColor = "chocolate";
        document.getElementById("B8").style.backgroundColor = "chocolate";
        document.getElementById("B9").style.backgroundColor = "chocolate";
        win();
    }
    else if (r1 != "-" && r4 == r7 && r7 == r1) {
        document.getElementById("B1").style.backgroundColor = "chocolate";
        document.getElementById("B4").style.backgroundColor = "chocolate";
        document.getElementById("B7").style.backgroundColor = "chocolate";
        win();
    }
    else if (r2 != "-" && r5 == r8 && r2 == r8) {
        document.getElementById("B2").style.backgroundColor = "chocolate";
        document.getElementById("B5").style.backgroundColor = "chocolate";
        document.getElementById("B8").style.backgroundColor = "chocolate";
        win();
    }
    else if (r3 != "-" && r3 == r6 && r6 == r9) {
        document.getElementById("B3").style.backgroundColor = "chocolate";
        document.getElementById("B6").style.backgroundColor = "chocolate";
        document.getElementById("B9").style.backgroundColor = "chocolate";
        win();
    }
    else if (r1 != "-" && r5 == r9 && r5 == r1) {
        document.getElementById("B1").style.backgroundColor = "chocolate";
        document.getElementById("B5").style.backgroundColor = "chocolate";
        document.getElementById("B9").style.backgroundColor = "chocolate";
        win();
    }
    else if (r3 != "-" && r3 == r5 && r5 == r7) {
        document.getElementById("B3").style.backgroundColor = "chocolate";
        document.getElementById("B5").style.backgroundColor = "chocolate";
        document.getElementById("B7").style.backgroundColor = "chocolate";
        win();
    }

}

function win()
{
    document.getElementById("pX").style.backgroundColor = "white";
    document.getElementById("pO").style.backgroundColor = "white";
    document.getElementById("backGroungGame").style.backgroundImage = "url('birthday.png')";
    if (document.getElementById("mahfe").textContent == "2") {

        document.getElementById("p1").innerHTML = parseInt(document.getElementById("p1").textContent) + 1;

    }

    else {
        document.getElementById("p2").innerHTML = parseInt(document.getElementById("p2").textContent) + 1;
    }

    if (document.getElementById("p1").textContent == "3" )
    {
        document.getElementById("sound").play();
        document.getElementById("pX").style.backgroundImage = "url('a2.png')"
        document.getElementById("cup1").innerHTML = "<img src='trophy.png' width='40%' height='100' > ";
        document.getElementById("playAgain").innerHTML = "START NEW GAME";
        
    }
    else if (document.getElementById("p2").textContent == "3")
    {
        document.getElementById("sound").play();
        document.getElementById("pO").style.backgroundImage = "url('a2.png')"
        document.getElementById("cup2").innerHTML = "<img src='trophy.png' width='40%' height='100' > ";
        document.getElementById("playAgain").innerHTML = "START NEW GAME";
        
    }
    
   
    notWorking();
}


function notWorking()
{
    document.getElementById("B1").disabled = true;
    document.getElementById("B2").disabled = true;
    document.getElementById("B3").disabled = true;
    document.getElementById("B4").disabled = true;
    document.getElementById("B5").disabled = true;
    document.getElementById("B6").disabled = true;
    document.getElementById("B7").disabled = true;
    document.getElementById("B8").disabled = true;
    document.getElementById("B9").disabled = true;
}

function playNewMatch()
{
    if (document.getElementById("mahfe").textContent == "1")
    {
        document.getElementById("mahfe").innerHTML = "2";
        document.getElementById("pX").style.backgroundColor = "white";
        document.getElementById("pO").style.backgroundColor = "yellowgreen";
        
    }
    else
    {
        document.getElementById("mahfe").innerHTML = "1";

        document.getElementById("pO").style.backgroundColor = "white";
        document.getElementById("pX").style.backgroundColor = "gold";

        

    }
    document.getElementById("B1").innerHTML = "-";
    document.getElementById("B2").innerHTML = "-";
    document.getElementById("B3").innerHTML = "-";
    document.getElementById("B4").innerHTML = "-";
    document.getElementById("B5").innerHTML = "-";
    document.getElementById("B6").innerHTML = "-";
    document.getElementById("B7").innerHTML = "-";
    document.getElementById("B8").innerHTML = "-";
    document.getElementById("B9").innerHTML = "-";

    document.getElementById("B1").style.backgroundColor = "white";
    document.getElementById("B2").style.backgroundColor = "white";
    document.getElementById("B3").style.backgroundColor = "white";
    document.getElementById("B4").style.backgroundColor = "white";
    document.getElementById("B5").style.backgroundColor = "white";
    document.getElementById("B6").style.backgroundColor = "white";
    document.getElementById("B7").style.backgroundColor = "white";
    document.getElementById("B8").style.backgroundColor = "white";
    document.getElementById("B9").style.backgroundColor = "white";
    Working();
}
function Working() {
    document.getElementById("B1").disabled = false;
    document.getElementById("B2").disabled = false;
    document.getElementById("B3").disabled = false;
    document.getElementById("B4").disabled = false;
    document.getElementById("B5").disabled = false;
    document.getElementById("B6").disabled = false;
    document.getElementById("B7").disabled = false;
    document.getElementById("B8").disabled = false;
    document.getElementById("B9").disabled = false;
}


function whereGoing()
{
    if(document.getElementById("playAgain").textContent=="Play Again")
    {
        document.getElementById("backGroungGame").style.backgroundImage = "none";
        playNewMatch();
    }
    else
    {
        location.reload(true);
    }
}

