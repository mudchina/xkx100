// Room: /d/heimuya/dating2.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "白虎堂");
	set("long", @LONG
这是『日月神教』下第二大堂：白虎堂的大厅，四目望去，一地都
是鲜血，显然不久前这里有一场大战。堂梁上有一块旧木匾(bian)。堂
上北壁上有几个血字(zi)。
LONG    );
	set("exits", ([
		"west" : __DIR__"baistep1",
		"east" : __DIR__"linjxd6",
	]));
	set("item_desc", ([
		"bian": "上面写到：长河落日，白虎在天；千秋万载，一统江湖 。\n",
		"zi" : "上面写到：华山弟子，势杀邪教。\n" 
	]) );
	set("no_clean_up", 0);
	set("coor/x", -3030);
	set("coor/y", 4020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}