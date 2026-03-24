# Aarvya Language Compiler 🚀

Aarvya is a custom programming language project developed as part of a compiler design assignment.  
This project demonstrates the core concepts of compiler construction including **lexical analysis** and **syntax parsing**.

---

## 📌 Project Overview

This project is divided into modules:

- **Module 1: Lexer**
  - Tokenizes input from `.arv` files
  - Identifies basic elements of the language

- **Module 2 & 3: Recursive Descent Parser**
  - Implements a parser using recursive functions
  - Parses arithmetic expressions based on grammar
  - Evaluates expressions during parsing

--- ## ⚙️ Grammar Used
E → T + E | T
T → F * T | F
F → (E) | digit


- `E` handles addition  
- `T` handles multiplication  
- `F` handles digits and parentheses  

---

## 💡 Features

- Recursive Descent Parsing  
- Expression Evaluation  
- Operator Precedence Handling  
- Parentheses Support  
- Simple and modular C implementation  

---

## ▶️ How to Run

### Compile
```bash
gcc parser.c -o parser

Execute
./parser.exe