//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "琴馆");
	set ("long", @LONG
这是一座飞檐高耸、画栋雕梁的亭子，匾额上题“高山流水”四个
大字。亭中悬一字画(zihua)。
LONG);
	set("item_desc", ([
		"zihua" : "这幅画上画的是伯牙“摔琴谢知音”的故事。画中还题有四句诗：
                    摔碎瑶琴凤尾寒
                    子期不在对谁弹
                    春风满面皆朋友
                    欲觅知音难上难\n"
	]));
	set("exits", ([
		"south" : __DIR__"qintai",
	]));
  
	set("coor/x", -1490);
	set("coor/y", -2110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
