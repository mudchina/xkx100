// Room: /d/5lt/fychang.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "放映场");
	set  ("long",  @LONG
这里是放映场，据说今天凌晨某部大片全球同步首映。天还未黑，
场内已经挤满了占座的村民。
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"west"  :  __DIR__"nroad3",
	]));

	set("no_fight", 1);
	set("coor/x", -140);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
