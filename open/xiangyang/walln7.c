// Room: /d/xiangyang/walln7.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "����ͷ");
	set("long", @LONG
�����������ı���ͷ��һЩ�α����ڳ�ͷѲ�ߣ�һ������
�������������ܸ����سǲ��ϣ�һЩ���������鹭�������
�ų��µĶ�����
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"southeast" : __DIR__"walle8",
		"westdown"  : __DIR__"walln5",
	]));
	set("objects", ([
		__DIR__"npc/ya"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -460);
	set("coor/y", -450);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}