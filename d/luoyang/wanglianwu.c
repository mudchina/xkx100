//  Room:  /d/luoyang/wanglianwu.c

inherit  ROOM;

void  create  ()
{
	set("short",  "练武厅");
	set("long",  @LONG
据说，王家威震豫鄂的武功，就是在这个练武厅里练出来的。可你
看见的也只不过是一个很寻常的屋子而已，唯一突出的，不过是东墙上
挂满的一壁单刀罢了。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south"  :  __DIR__"wanghuating",
	]));
	set("no_clean_up", 0);
	set("coor/x", -600);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}