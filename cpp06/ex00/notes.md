receive str
	-> analyze str :
			- if length == 1 && isascii => char
			- if sign au debut ou pas + isdigit only => int / double (?)
			- if sign au debut ou pas + isdigit && 1 point => double
			- if sign au debut ou pas + isdigit && 1 point && f a la fin ==> float
	-> convert str to good type
	-> send to converter to types