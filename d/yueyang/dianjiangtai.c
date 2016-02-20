// Room: /d/yueyang/dianjiangtai.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "点将台");
	set("long", @LONG
下了石阶来到水边一个平台，此台便是三国大将鲁肃在此点兵发令
的“点将台”。点将台南侧不远有一系铁链的大铁枷，这条硕大无朋的
大铁枷据说是拦江御敌用的。
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"shijie7",
	]));
	set("coor/x", -1440);
	set("coor/y", -2280);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
