// Room: /d/lingxiao/andao.c
// Last Modified by winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","暗道");
	set("long",@LONG 
这是一条凌霄城的暗道，看来是凌霄城里什么人出入的秘密通道。
在墙上插着的几根火把所散发出的光芒下，可以看到地下有一本书，不
知道是哪个粗心鬼掉在这里的。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"out"       : __DIR__"muwu",
		"northdown" : __DIR__"didi",
	]));
	set("objects", ([
		BOOK_DIR+"sword_book3" : 1,
	]));
	set("coor/x", -30990);
	set("coor/y", -8910);
	set("coor/z", 130);
	setup();
	replace_program(ROOM);
}

