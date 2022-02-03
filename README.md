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
<pre>Vigenere.exe filename mode password</pre>
<h3>Linux Syntax</h3>
<pre>Vigenere filename mode password</pre>

<p>I also included the function <code>Vigenere help</code> or <code>Vigenere.exe help</code> to show the syntax in shell.</p>

<h2>Use</h2>
<h3>Mode 'e'</h3>
<p>Example:<br>
To encrypt a simple textfile, you have to write <code>Vigenere.exe test.txt e password</code> in your shell.<br>
The given file of test.txt will be printed in console and the program is asking for a new filename for the encrypted file.
The file will be created with all encrypted information. Warning: Existing files will be overwritten.

Test-file with password of <code>password</code>:

<pre>this is a test text</pre>

Encrypted-file:

<pre>ihak eg r wtsl lalk</pre>
</p>
<h3>Mode 'd'</h3>
<p>Example:<br>
To decrypt a simple textfile, you have to write <code>Vigenere.exe test.txt d password</code> in your shell.<br>
The given file of test.txt will be printed in console and the program is asking for a new filename for the decrypted file.
The file will be created with all decrypted information. Warning: Existing files will be overwritten.

Test-file with password of <code>password</code>:

<pre>ihak eg r wtsl lalk</pre>

Decrypted-file:

<pre>this is a test text</pre>
</p>

<h2>Notes</h2>
<p>This program cannot encrypt or decrypt symbols out of this range <code>a-z</code> or <code>A-Z</code>.<br>
Make sure your textfile does not contain any other symbols. And your simple textfile should be coded in ANSI.</p>

<h2>Security</h2>
<p>If you want to encrypt files make sure that the key is very long, because its very easy to crack small ones.</p>

<h2>Information about Vigenere algorithm</h2>
<p>https://en.wikipedia.org/wiki/Vigenère_cipher</p>
