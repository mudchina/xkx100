// tygate1.c ÌÒÔ°Àé°Ê
// by Marz 

inherit ROOM;

void create()
{
	set("short", "ÌÒÔ°Àé°Ê");
	set("long", @LONG
Äã×ßÔÚÒ»ÌõÍ¨ÍùÌÒÊ÷ÁÖÉî´¦µÄÐ¡µÀÉÏ£¬Ç°ÃæÓÐ¸öÀé°ÊÃÅ(fence)¡£
LONG );
	set("outdoors", "wudang");
	set("item_desc",([
		"fence"	:	"\n\t\t\tÀé°ÊÃÅÉÏÓÐÊ×Ê«£º\n\n\n" 
			"\t\t¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë\n"
			"\t\t¡Ë¡Ë¡Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡Ë¡Ë¡Ë\n"
			"\t\t¡Ë¡Ë¡Ë¡¡Ó¦¡¡Á¯¡¡åì¡¡³Ý¡¡Ó¡¡¡²Ô¡¡Ì¦¡¡¡Ë¡Ë¡Ë\n"
			"\t\t¡Ë¡Ë¡Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡Ë¡Ë¡Ë\n"
			"\t\t¡Ë¡Ë¡Ë¡¡Ð¡¡¡¿Û¡¡²ñ¡¡ìé¡¡¾Ã¡¡²»¡¡¿ª¡¡¡Ë¡Ë¡Ë\n"
			"\t\t¡Ë¡Ë¡Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡Ë¡Ë¡Ë\n"
			"\t\t¡Ë¡Ë¡Ë¡¡´º¡¡É«¡¡Âú¡¡Ô°¡¡¹Ø¡¡²»¡¡×¡¡¡¡Ë¡Ë¡Ë\n"
			"\t\t¡Ë¡Ë¡Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡Ë¡Ë¡Ë\n"
			"\t\t¡Ë¡Ë¡Ë¡¡Ò»¡¡Ö¦¡¡ºì¡¡ÐÓ¡¡³ö¡¡Ç½¡¡À´¡¡¡Ë¡Ë¡Ë\n"
			"\t\t¡Ë¡Ë¡Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡Ë¡Ë¡Ë\n"
			"\t\t¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë\n\n\n",
							
	]));
	set("exits", ([
		"south" : __DIR__"tyroad10",
	]));
        set("objects", ([
                "/clone/medicine/vegetable/gancao" : random(2),
        ]));
	set("coor/x", -1970);
	set("coor/y", -920);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}