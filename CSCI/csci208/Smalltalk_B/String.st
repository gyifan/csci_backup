﻿'From Squeak4.1 of 17 April 2010 [latest update: #9957] on 9 February 2012 at 5:04:35 pm'!
 arg

	"Convert from UTC format" 	^ DateAndTime fromString: self! !
	"convert from [nnnd]hh:mm:ss[.nanos] format. [] implies optional elements"

	^ Duration fromString: self
! !
	^ TimeStamp fromString: self! !
	"Answer a VersionNumber"

	^VersionNumber fromString: self! !