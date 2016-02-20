//  Room:  /d/5lt/fantexi.c

inherit  ROOM;

void  create  ()
{
	set("short",  "饭特溪");
	set("long",  @LONG
这里就是传说中的饭特溪了。好一条清亮的小溪！你把手伸进湍湍
流淌的小溪，冰凉的水丝一般地涌入指缝又伸懒腰似的从其中舒展开来，
被泉水滋润一样的舒服。
LONG);
	set("exits",  ([
		"northeast"  :  __DIR__"kongdi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "5lt");
	set("coor/x", -195);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}