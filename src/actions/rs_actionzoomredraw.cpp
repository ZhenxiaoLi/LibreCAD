/****************************************************************************
**
** This file is part of the CADuntu project, a 2D CAD program
**
** Copyright (C) 2010 R. van Twisk (caduntu@rvt.dds.nl)
** Copyright (C) 2001-2003 RibbonSoft. All rights reserved.
**
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software 
** Foundation and appearing in the file gpl-2.0.txt included in the
** packaging of this file.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** 
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**
** This copyright notice MUST APPEAR in all copies of the script!  
**
**********************************************************************/

#include "rs_actionzoomredraw.h"
//Added by qt3to4:
#include <q3mimefactory.h>


/**
 * Constructor.
 *
 * @param keepAspectRatio true: keep same zoom value for x/y.
 *                        false: adjust both x and y individually
 */
RS_ActionZoomRedraw::RS_ActionZoomRedraw(RS_EntityContainer& container,
        RS_GraphicView& graphicView)
        :RS_ActionInterface("Redraw", container, graphicView) {
}


QAction* RS_ActionZoomRedraw::createGUIAction(RS2::ActionType /*type*/, QObject* /*parent*/) {
	// tr("Redraw")
	QAction* action = new QAction(tr("&Redraw"), NULL);
	action->setIcon(QIcon(":/actions/zoomredraw.png"));
	action->setShortcut(QKeySequence::Cut);
	//action->zetStatusTip(tr("Redraw"));
	
    return action;
}


void RS_ActionZoomRedraw::init(int status) {
    RS_ActionInterface::init(status);
    trigger();
}



void RS_ActionZoomRedraw::trigger() {
    graphicView->redraw();
    finish();
}

// EOF
