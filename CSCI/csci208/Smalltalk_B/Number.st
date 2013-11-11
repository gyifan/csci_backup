'From Squeak4.1 of 17 April 2010 [latest update: #9957] on 9 February 2012 at 5:04:53 pm'!
 aNumber 

	^ Duration nanoSeconds: self asInteger
! !

	^ self sign days! !

	^ Duration days: self! !

	^ self sign hours
! !

	^ Duration hours: self! !

	^ self sign milliSeconds
! !

	^ Duration milliSeconds: self
! !

	^ self sign minutes
! !

	^ Duration minutes: self! !

	^ self sign nanoSeconds
! !

	^ Duration nanoSeconds: self.! !

	^ self sign seconds
! !

	^ Duration seconds: self! !
	"Return a Number with the same sign as aNumber"

	^ aNumber positive ifTrue: [self abs] ifFalse: [self abs negated].! !

	^ self sign weeks
! !

	^ Duration weeks: self! !