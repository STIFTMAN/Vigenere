<h1>Vigenere</h1>
<p>This small C-program is able to encrypt and decrypt simple textfiles using Vigenere algorithm.</p>

<h2>Files</h2>
<p>There is a C-file, containing the code and a compiled file. You can use the compiled file directly, but if there are any problems with your operating system to support this file, you can compile the C-file on your own.</p>

<h3>Compiling</h3>
<p>I used a GNU compiler.<br>
Write <code>gcc -Wall -Wpedantic -o Vigenere Vigenere.c</code> in your shell.<br>
There should be a new compiled file called <code>Vigenere</code> or <code>Vigenere.exe</code>.</p>


<h2>Syntax</h2>
<h3>Windows Syntax</h3>
<p><code>Vigenere.exe filename mode password</code></p>
<h3>Linux Syntax</h3>
<p><code>Vigeere filename mode password</code></p>

<p>I also included the function <code>Vigenere help</code> or <code>Vigenere.exe help</code> to show the syntax in shell.</p>

<h2>Use</h2>
<h3>Mode 'e'</h3>
<p>Example:<br>
To encrypt a simple textfile, you have to write <code>Vigenere.exe test.txt e password</code> in your shell.<br>
The given file of test.txt will be printed in console and the program is asking for a new filename for the encrypted file.
The file will be created with all encrypted information.

Test-file with password of <code>password</code>:

<code>this is a test text</code>

Encrypted-file:

<code>ihak eg r wtsl lalk</code>
</p>
<h3>Mode 'd'</h3>
<p>Example:<br>
To decrypt a simple textfile, you have to write <code>Vigenere.exe test.txt d password</code> in your shell.<br>
The given file of test.txt will be printed in console and the program is asking for a new filename for the decrypted file.
The file will be created with all decrypted information.

Test-file with password of <code>password</code>:

<code>ihak eg r wtsl lalk</code>

Decrypted-file:

<code>this is a test text</code>
</p>

<h2>Notes</h2>
<p>This program cannot encrypt or decrypt symbols out of this range <code>a-z</code> or <code>A-Z</code>.<br>
Make sure your textfile does not contain any other symbols. And your simple textfile should be coded in ANSI.</p>
