// /d/changan/huachang.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "花场");
	set  ("long",  @LONG
虽说洛阳牡丹闻名天下，但长安菊花却也毫不逊色。这片空地满种
“黄金甲”，黄巢在世，想必是十分喜欢的了。
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"south"  :  __DIR__"eastroad1",
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5020);
	set("coor/y", 1010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
