//  Room:  /d/5lt/kongdi.c

inherit  ROOM;

void  create  ()
{
	set("short",  "空地");
	set("long",  @LONG
这里是溪边一块平坦的空地。空地的主人大概没有什么闲暇，只是
略微平整一下，种了些绿草。村里的宠物们经常在这儿玩耍。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"southwest"  :  __DIR__"fantexi",
		"north"      :  __DIR__"wroad4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "5lt");
	set("coor/x", -190);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}