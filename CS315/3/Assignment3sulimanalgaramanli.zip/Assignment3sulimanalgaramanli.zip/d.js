
function validateFirstName(x) {
    if (x == "")
        return "No first name was entered.\n";
    else
        return "";
}
function validateLastName(x) {
    if (x == "")
        return "No last name was entered.\n";
    else
        return "";
}
function validateemail(x) {
    if (x == "")
        return "No email was entered.\n";
    if (!(x.indexOf(".") > 0 && x.indexOf("@") > 0) || /[^a-zA-Z0-9.@_-]/.test(x)) {
        return "The Email address is invalid.\n";
    }
    return "";
}
function validatecode(x) {
    if (x == "")
        if (x == "")
            return "No Area Code was entered.\n";
    if (isNaN(+x)) {
        return "Area Code Must be a number.\n";
    }
    return "";
}
function validatenumber(x) {
    if (x == "")
        return "No Phone Number was entered.\n";
    if (isNaN(+x)) {
        return "phone Must be a number.\n";
    }
    return "";
}

function validate(form) {
    x = 0;
    fail = validateFirstName(form.FName.value);
    fail += validateLastName(form.LName.value);
    fail += validateemail(form.email.value);
    fail += validatecode(form.code.value);
    fail += validatenumber(form.Number.value);
    // console.log(document.getElementById("cake").checked);
    var m = "";
    if (document.getElementById("cake").checked) {
        x += 1;
       
        if (document.getElementById("cakeq").value <= 0) {
            fail += "Enter positive number for Quantity of cake.\n";
        }
        else {
            
            cakePrice = parseFloat(document.getElementById("cakePrice").textContent)
            totalCakePraic = cakePrice * parseFloat( document.getElementById("cakeq").value);
            m += "cake amount " + document.getElementById("cakeq").value + " total =" + totalCakePraic + " DLY.\n";
        }
    }
    if (document.getElementById("banana").checked) {
        x += 1;
        if (document.getElementById("bananaq").value <= 0){
            fail += "Enter positive number for Quantity of banana.\n";
        }
        else {

        cakePrice = parseFloat(document.getElementById("bananaPrice").textContent)
            totalCakePraic = cakePrice * parseFloat(document.getElementById("bananaq").value);
            m += "banana amount " + document.getElementById("bananaq").value + " total =" + totalCakePraic + " DLY.\n";
        }
    }

if (document.getElementById("Apple").checked) {
        x += 1;
        if (document.getElementById("Appleq").value <= 0) {
            fail += "Enter positive number for Quantity of Apple.\n";
        }
        else {
            
            cakePrice = parseFloat(document.getElementById("ApplePrice").textContent)
            totalCakePraic = cakePrice * parseFloat(document.getElementById("Appleq").value);
            m += "Apple amount " + document.getElementById("Appleq").value + " total =" + totalCakePraic + " DLY.\n";
        }
    }
    if (document.getElementById("Tuna").checked) {
        x += 1;
        if (document.getElementById("Tunaq").value <= 0) {
            fail += "Enter positive number for Quantity of Tuna.\n";
        }
        else {
            
            cakePrice = parseFloat(document.getElementById("TunaPrice").textContent);
           
            totalCakePraic = cakePrice * parseFloat(document.getElementById("Tunaq").value);
            m += "Tuna amount " + document.getElementById("Tunaq").value + " total =" + totalCakePraic + " DLY.\n";
           
        }
    }

    if (x == 0)
        fail += "Chose your order.\n "

    if (fail == "") {
       // viewData(form);
        var mes = form.FName.value + " " + form.LName.value + "\nyou select :\n" + m;
        alert(mes);
        return true;
    } else {
        alert(fail);
        return false;
    }
}


function viewData(form) {
 

}

//cakePrice = parseFloat(document.getElementById("cakePrice").textContent); //get the cake price from the cakep id and parse the text Content to float
//applePrice = parseFloat(document.getElementById("apple").textContent); //get the apple price from the applep id and parse the text Content to float
//bananaPrice = parseFloat(document.getElementById("banana").textContent); //get the banana price from the bananap id and parse the text Content to float
//tunaPrice = parseFloat(document.getElementById("tuna").textContent); //get the tuna price from the tunap id and parse the text Content to float


