#include "itkImageFileReader.h"
#include "itkGDCMImageIO.h"

#include "QuickView.h"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " DicomImage" << std::endl;
		return EXIT_FAILURE;
	}

	using InputPixelType = signed short;
	constexpr unsigned int InputDimension = 2;

	using InputImageType = itk::Image< InputPixelType, InputDimension >;

	using ImageIOType = itk::GDCMImageIO;
	ImageIOType::Pointer gdcmImageIO = ImageIOType::New();

	using ReaderType = itk::ImageFileReader< InputImageType >;
	ReaderType::Pointer reader = ReaderType::New();
	reader->SetFileName(argv[1]);
	reader->SetImageIO(gdcmImageIO);

	try
	{
		reader->Update();
	}
	catch ( itk::ExceptionObject &ex)
	{
		std::cerr << "exception in file reader " << std::endl;
		std::cerr << ex << std::endl;
		return EXIT_FAILURE;
	}

	QuickView viewer;
	viewer.AddImage(reader->GetOutput());
	viewer.Visualize();

	return EXIT_SUCCESS;
}