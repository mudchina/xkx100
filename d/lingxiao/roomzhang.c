// Room: /d/lingxiao/roomzhang.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","居室");
	set("long",@LONG 
走进这里，出现在你眼前的是大大小小的药罐。在这里住的是凌霄
城的六代弟子张万年，他为人厚道，所以白自在放心地把管理凌霄城一
些稀世药物的任务交给了他。不过据说他跟王万仞向来交好，经常把一
些珍贵的药酒给那家伙喝。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"zoulang2", 
	]));
	set("objects", ([  
		__DIR__"npc/zhang" : 1,
		__DIR__"obj/icesword" : 3,
	]));
	set("coor/x", -30990);
	set("coor/y", -8880);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

