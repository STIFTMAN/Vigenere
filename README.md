# Vigenere
This small C-program is able to encrypt and decrypt simple textfiles using Vigenere algorithm.

## Files
There is a C-file, containing the code and a compiled file. You can use the compiled file directly, but if there are any problems with your operating system to support this file, you can compile the C-file on your own.

### Compiling
I used a GNU compiler.
Write <code>gcc -Wall -Wpedantic -o Vigenere Vigenere.c</code> in your shell.
There should be a new compiled file called <code>Vigenere</code> or <code>Vigenere.exe</code>.

## Syntax
### Windows Syntax
<pre>Vigenere.exe filename mode password</pre>
### Linux Syntax
<pre>Vigenere filename mode password</pre>

I also included the function <code>Vigenere help</code> or <code>Vigenere.exe help</code> to show the syntax in shell.

## Use
### Mode '-e'
Example:
To encrypt a simple textfile, you have to write <code>Vigenere.exe test.txt e password</code> in your shell.
The program is asking for a new filename for the encrypted file.
The file will be created with all encrypted information. Warning: Existing files will be overwritten.

Test-file with password of <code>password</code>:

<pre>this is a test text</pre>

Encrypted-file:

<pre>ihak eg r wtsl lalk</pre>

### Mode '-d'
Example:
To decrypt a simple textfile, you have to write <code>Vigenere.exe test.txt d password</code> in your shell.
The program is asking for a new filename for the decrypted file.
The file will be created with all decrypted information. Warning: Existing files will be overwritten.

Test-file with password of <code>password</code>:

<pre>ihak eg r wtsl lalk</pre>

Decrypted-file:

<pre>this is a test text</pre>

### Mode '-p'
Additional mode for '-e' or '-d' for printing the results in console. Using '-ep', '-pe' , '-dp' or 'pd'.

## Notes
This program cannot encrypt or decrypt symbols out of this range <code>a-z</code> or <code>A-Z</code>.
Make sure your textfile does not contain any other symbols. And your simple textfile should be coded in ANSI.

## Security
If you want to encrypt files make sure that the key is very long, because its very easy to crack small ones.

## Information about Vigenere algorithm
https://en.wikipedia.org/wiki/Vigenère_cipher
