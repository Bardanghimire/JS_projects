class Calculator {
    constructor(screenBig, screenSmall, times, divide) {
        this.screenBig = screenBig
        this.screenSmall = screenSmall

        this.divide = divide.toString()
        this.times = times.toString()

        this.operator = undefined

        this.firstNumber = ''
        this.secondNumber = ''

        this.frontScreen = ''
        this.backScreen = ''
    }
    clearAll() {
        this.frontScreen = ''
        this.backScreen = ''
        this.operator = undefined

    }
    delete() {
        this.frontScreen = this.frontScreen.toString().slice(0, -1)

    }
    plusToMinus() {
        this.frontScreen = -this.frontScreen;
    }
    AppendNumber(number) {
        this.frontScreen = this.frontScreen.toString() + number.toString()
        this.firstNumber = this.frontScreen;
    }
    Operand(operator) {
        this.operator = operator.toString();
        this.frontScreen += this.operator.toString()

    }
    seperate(number) {
        let anothernumber = '';
        let anothernumber1 = '';
        this.count = 0;
        this.number = number.split("");
        for (let i = 0; i < number.length; i++) {
            if (number[i] != this.operator) {
                this.count++;
            }
            else {
                break
            }
        }
        for (let i = 0; i < this.count; i++) {
            anothernumber += this.number[i];
        }
        for (let i = this.count + 1; i < this.number.length; i++) {
            anothernumber1 += this.number[i];
        }
        return [anothernumber, anothernumber1]
    }

    calculate() {
        let first, second
        this.backScreen = this.frontScreen
        let numbers = this.seperate(this.frontScreen)

        first = numbers[0]
        second = numbers[1]
        let finalAns;
        first = parseFloat(first)
        second = parseFloat(second)
        switch (this.operator) {
            case '+':
                finalAns = first + second;
                break
            case '-':
                finalAns = first - second
                break
            case this.divide:
                finalAns = first / second
                break
            case this.times:
                finalAns = first * second
                break
            default:
                return
        }
        this.frontScreen = finalAns;
    }
    display() {
        this.screenBig.innerText = this.frontScreen;
        this.screenSmall.innerText = this.backScreen;
    }
}



//declaring varible which select the tags from our html code.
let numbers = document.querySelectorAll('.number')

let operator = document.querySelectorAll(".operator")

let clearall = document.querySelector(".clearall");

let delOne = document.querySelector(".clear");

let screenBig = document.querySelector(".screen-front")

let screenSmall = document.querySelector(".screen-previous")

let equal = document.querySelector(".equal")

let exit = document.querySelector(".exit")

let times = document.querySelector(".times").innerText

//take Text inside from .divide class send it to the Calculator class

let divide = document.querySelector(".divide").innerText

let plusminus = document.querySelector(".plusminus")

const calculator = new Calculator(screenBig, screenSmall, times, divide);


//Listining events 
exit.addEventListener("click", () => {
    window.opener = self;
    window.close();
})

numbers.forEach(button => {
    button.addEventListener("click", () => {
        calculator.AppendNumber(button.innerText)
        calculator.display();
    })
})

operator.forEach(button => {
    button.addEventListener("click", () => {
        calculator.Operand(button.innerText)
        calculator.display();
    })
})

clearall.addEventListener("click", () => {
    calculator.clearAll();
    calculator.display();
})

delOne.addEventListener("click", () => {
    calculator.delete()
    calculator.display()
})
equal.addEventListener("click", () => {
    calculator.calculate();
    calculator.display();
})
plusminus.addEventListener("click", () => {
    calculator.plusToMinus();
    calculator.display();
})