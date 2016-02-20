// Room: /d/fuzhou/yijinfang.c
// Last Modifyed by Evil on Sep. 10 2002

inherit ROOM;

void create()
{
	set("short", "衣锦坊");
	set("long", @LONG
旧名通潮巷。宋代宣和年间(1119—1125年)陆蕴、陆藻兄弟居于此
地，两兄弟才华横送，名重一时。陆蕴官任福州知州，陆藻官任泉州知
州，两人回乡时命此坊为“棣锦坊”。南宋淳熙年间(1174—1189年)，
王益样任江东提刑，退休后也居于此地，将棣锦改名为衣锦，以示衣锦
返乡之意。 
LONG );
	set("exits", ([
		"east"    : __DIR__"nanhoujie1",	
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1833);
	set("coor/y", -6310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
