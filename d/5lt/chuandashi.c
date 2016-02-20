// Room: /d/5lt/chuandashi.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "传达室");
	set  ("long",  @LONG
这里是村支部的传达室。你埋头加快脚步刚从门口走过，却瞥见传
达室的大爷正望着你，目光炯炯，十分警惕。
LONG);
	set("exits",  ([  //sizeof()  ==  3
		"north"  :  __DIR__"yuelanshi",
		"west"   :  __DIR__"czoffice",
		"east"   :  __DIR__"nroad2",
	]));
	set("no_fight", 1);
	set("coor/x", -160);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
