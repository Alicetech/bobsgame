
#include "Gwen/Gwen.h"
#include "Gwen/Controls/HorizontalSplitter.h"
#include "Gwen/Controls/Button.h"

using namespace Gwen;
using namespace Controls;

GWEN_CONTROL_CONSTRUCTOR(HorizontalSplitter)
{

	m_HSplitter = new SplitterBar(this);
	m_HSplitter->SetPos(128, 0);
	m_HSplitter->onDragged.Add(this, &HorizontalSplitter::OnHorizontalMoved);
	m_HSplitter->SetCursor(Gwen::CursorType::SizeWE);

	m_fHVal = 0.5f;

	SetPanel(0, NULL);
	SetPanel(1, NULL);

	SetSplitterSize(5);
	m_iZoomedSection = -1;
}


void HorizontalSplitter::UpdateHSplitter()
{
	m_HSplitter->MoveTo((Width() - m_HSplitter->Width()) * (m_fHVal), m_HSplitter->Y());
}





void HorizontalSplitter::OnHorizontalMoved(Controls::Base* /*control*/)
{
	m_fHVal = CalculateValueHorizontal();
	Invalidate();
}




float HorizontalSplitter::CalculateValueHorizontal()
{
	return (float)m_HSplitter->X() / (float)(Width() - m_HSplitter->Width());
}



void HorizontalSplitter::Layout(Skin::Base* /*skin*/)
{

	m_HSplitter->SetSize(m_fBarSize, Height());


	UpdateHSplitter();


	if (m_iZoomedSection == -1)
	{
		if (m_Sections[0])
		{
			m_Sections[0]->SetBounds(0, 0, m_HSplitter->X(), Height());
		}

		if (m_Sections[1])
		{
			m_Sections[1]->SetBounds(m_HSplitter->X() + m_fBarSize, 0, Width() - (m_HSplitter->X() + m_fBarSize), Height());
		}

	}
	else
	{
		//This should probably use Fill docking instead
		m_Sections[m_iZoomedSection]->SetBounds(0, 0, Width(), Height());
	}
}

void HorizontalSplitter::SetPanel(int index, Controls::Base* pPanel)
{
	Debug::AssertCheck(index >= 0 && index <= 1, "HorizontalSplitter::SetPanel out of range");
	m_Sections[index] = pPanel;

	if (pPanel)
	{
		pPanel->Dock(Pos::GwenNone);
		pPanel->SetParent(this);
	}

	Invalidate();
}

Controls::Base* HorizontalSplitter::GetPanel(int i)
{
	return m_Sections[i];
}


void HorizontalSplitter::ZoomChanged()
{
	onZoomChange.Call(this);

	if (m_iZoomedSection == -1)
	{
		onUnZoomed.Call(this);
	}
	else
	{
		onZoomed.Call(this);
	}
}

void HorizontalSplitter::Zoom(int section)
{
	UnZoom();

	if (m_Sections[section])
	{
		for (int i = 0; i < 2; i++)
		{
			if (i != section && m_Sections[i])
			{
				m_Sections[i]->SetHidden(true);
			}
		}

		m_iZoomedSection = section;
		Invalidate();
	}

	ZoomChanged();
}

void HorizontalSplitter::UnZoom()
{
	m_iZoomedSection = -1;

	for (int i = 0; i < 2; i++)
	{
		if (m_Sections[i])
		{
			m_Sections[i]->SetHidden(false);
		}
	}

	Invalidate();
	ZoomChanged();
}
