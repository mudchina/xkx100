//  Room:  /d/luoyang/road2.c

inherit  ROOM;

void  create  ()
{
	set("short",  "大官道");
	set("long",  @LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。路边还开着些不
入流的牡丹花，一看就知道是洛阳城的辖地。东面就是通往扬州的大官
道，西面则是著名的洛阳城，而东北面则是著名的旅游胜地：白马寺。
寺庙进香的游客很多，路边草地已经给踩得相当平了。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"      :  __DIR__"hulaoguan",
		"west"      :  __DIR__"eastgate",
		"south"     :  __DIR__"road7",
		"northeast" :  __DIR__"baimasi",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -200);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
