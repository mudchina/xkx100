// Room: /d/5lt/youju.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "邮局");
	set  ("long",  @LONG
这里是一家邮局。时近黄昏，工作人员正忙着完成手上的事情准备下班。
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"east"  :  __DIR__"sroad2",
	]));
	set("objects",  ([
	]));
	set("coor/x", -160);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
