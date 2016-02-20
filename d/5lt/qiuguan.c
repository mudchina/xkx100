// Room: /d/5lt/qiuguan.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "羽毛球馆");
	set  ("long",  @LONG
这里是羽毛球馆，开门不到半柱香的功夫，馆内已经没有空着的场
地了，场边站满了拿着球拍观战的人。
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"east"  :  __DIR__"nroad3",
	]));
	set("no_fight", 1);
	set("coor/x", -160);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
