// Room: /d/qilian/zhutishan.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "朱提山");
	set("long", @LONG
此山通山由赤土构成，远望尤如红玛瑙帽顶，所以叫朱提。其山为
祈连诸山中最矮的一座，大概因为土质不好，少有生迹，唯山顶有几处
黑草丛生之处。但听说常有剧毒长虫出没，令人颇感费解。
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"northdown" : __DIR__"yongchang",
		"southwest" : __DIR__"datongling",
	]));
	set("objects", ([
		"/d/shenlong/npc/fushe" : random(2),
		"/d/shenlong/npc/dushe" : random(2),
	]));
	set("coor/x", -5000);
	set("coor/y", 10000);
	set("coor/z", 5);
	setup();
	replace_program(ROOM);
}